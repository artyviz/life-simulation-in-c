// SmoothLife
//
// 2D integrate shader


const float pi = 6.283185307;

uniform int method, nsnms;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform sampler2D tex2;
uniform sampler2D tex3;


void main()
{
	float snm1, snm2, snm3;
	float g;

	if (nsnms==1)
	{

		snm1 = texture2D (tex0, gl_TexCoord[0].xy).r;
		g = texture2D (tex1, gl_TexCoord[1].xy).r;
		gl_FragColor.r = clamp (g+snm1, 0.0, 1.0);

	}
	else
	{

		snm1 = texture2D (tex0, gl_TexCoord[0].xy).r;
		snm2 = texture2D (tex1, gl_TexCoord[1].xy).r;
		snm3 = texture2D (tex2, gl_TexCoord[2].xy).r;
		g = texture2D (tex3, gl_TexCoord[3].xy).r;

		if (method==1)
		{
			g = clamp (g + snm1, 0.0, 1.0);
			g = clamp (g + snm2, 0.0, 1.0);
			g = clamp (g + snm3, 0.0, 1.0);
			gl_FragColor.r = g;
		}
		else
		{
			g += (snm1 + snm2 + snm3)/3.0;
			//g += (snm1 + snm2 + 1.5*snm3)/3.5;
			gl_FragColor.r = clamp (g, 0.0, 1.0);
		}
	}
}
