# Life Simulation - Gradient Intensity Levels (Game of Life)

## Description

This project implements a **Life Simulation** based on gradient intensity levels and uses a mathematical approach inspired by the **Lenia** model. The simulation uses a cellular automaton system where each cell's state is represented by characters, corresponding to varying intensity levels. The simulation uses **fast Fourier transforms** (FFT) to efficiently compute and update the state of each cell with periodic boundary conditions.

The grid is updated continuously, with each cell’s state based on its neighbors, and the resulting state is displayed using characters that represent different intensity levels, from the lowest (.) to the highest (#).

## Features

- **Gradient Intensity Levels**: Cells are represented by characters from `.` (lowest intensity) to `#` (highest intensity).
- **Dynamic Simulation**: Each grid cell's state evolves over time based on local neighborhood interactions.
- **Periodic Boundary Conditions**: The simulation wraps around the edges of the grid, ensuring continuous updates using FFT for efficient computation.
- **Customizable Parameters**: Various parameters, such as diffusion coefficients and reaction rates, can be adjusted to alter the simulation's behavior.

## Technologies

- **C**: Primary programming language for implementing the simulation.
- **Mathematical Modeling**: Fast Fourier Transform (FFT) for efficient periodic boundary calculations.
- **Gradient Intensity Representation**: Cells' states are denoted using characters with intensity levels.

## Setup and Installation

### Prerequisites

1. A C compiler (such as `gcc`).
2. Basic knowledge of compiling and running C programs.
3. Optionally, FFT libraries if you choose to implement them.

### Installation Steps

1. **Clone the repository**:
2. Compile the program: gcc -o lifesim lifesim.c -lm
3. Here, -lm links the math library for mathematical functions
4. Run the simulation: ./lifesim
The simulation will continuously display the grid using characters that represent different intensity levels.

Usage
Display Output: The simulation prints the grid at each time step, updating the state of each cell based on its interactions with neighboring cells.

Grid Representation: Each character in the grid corresponds to an intensity level:

. : Lowest level
- : Gradually increasing intensity
c : Mid level
o : Higher level
# : Highest level


Example Output
The output will be a grid that looks something like this (showing a few rows of the simulation):


                                                                    --cc==--  cc==  oo    ==  ==  ==..cc  ==  ==  ..==oo  ..        oo
                                                                                  ..cccc  ..        ==  ..==--cc--==      cccc==----
                                                                            ..                cc==      --    ..==--    ====--cc..--..
                                                                    oo..    ==    oo==aaoo  aa  aaooaaaaccoo  aa  --  oo--..        ==
                                                                    ==..    --==oo  ..AAoo--AA  ooaa--ccoooo--cc--....==oocc--  cc..
                                                                        --..  ..==aa  AA..aaoooo====cc  ..==..  ccoo      --    --
                                                                    ..cc      --aa    ..--..--    AAccccaa  cc  --    ..  ====    ==
                                                                    ..cc==    aa..----      oo  cc--  cc  ==    ==            oo==--cc
                                                                    ..    oo====  --    ......    ====..==oo==      oo==      cc  ..
                                                                    ==ccoo--    --      ..  ..  oo==  ==            cccc    cc  ==  cc
                                                                    cc    cc..  ==    oocc--====  ==--  ....--cc  ..  --oo  ..aaaa..
                                                                            cc    ..  ==  oo..  ..cc      ====..        ..oooo  ----==
                                                                    ..            oo              cc    ------oo  ..    aacccc====  --
                                                                    ..  ==oooo    ==--..==ccoo          --  --  ==--==--  ooaa  cc....
                                                                    ==..oo    --      cc      ==    --cc----        ..  aaoo..==  ====
                                                                          ====cc==      --oo            --cccc--cc==oo..  AAccoo--  --
                                                                    ==..  ==        oo  oo  ====    ..  ==--..        --  ..AAcc==----
                                                                          ..cc        ..      --  ..  ==  --        oo    ....oocccc--
                                                                      --==..oo      cc  ==  cc..  ====--  cc    ==  --  cc  cc
                                                                      cc==  cc  ..  --==oooo  oo..--cc  ====..  cc    cc------  ..----
                                                                    cc    cc    ==..  ..      --....cc  --==    cc==cc  --..    ..  --
                                                                        ==oocc==            ..cc      ==  cc....--  ====--        ==
                                                                        ==  aa      oo    --==--        oo==cc..    oo  --      cc  oo
                                                                    cc  ==ooooAAcc==    oo  ..--  oocccc  --==  oo  ..--oooo....
                                                                      --  aa----..==cc..----oo==--cc      --oo    oo..        ..cc==
                                                                      ==  ==ccoo--      aa  aa====  ==  ----oocccc..oo..      oo
                                                                    ==----  ====ccAAoooo--ooaaoo==          ccaaAAAAaaccccaa  cc--oo
                                                                        cc    ..====  ccAAooaacc    --        ccccaa==aa..    ==  --
                                                                            ====oo  AAAA--aaooaa..====  --==cc  ==ooaa==
                                                                      ..  ==    ==ooooaacc..AA..AA        oo==..aaoo  ..----  oo  ==--
                                                                      cc    cc..==  ccoo..==..ooAA          ..--..      oo==  ..  --
                                                                        ==  cc  ==..  ==  --oo==..oooo  oo  oo    ..      ..cc..  ====
                                                                    cccc  ..==--..    ..  cc--  cc  ..oo====  ==  ..--  ..--    --



and 


                                                                    ..      ..    --                ..              --            --
                                                                                    ....                                  ....
                                                                                              ..                              ..
                                                                    --            --  ==--  ==  ==--====..--  ==      --
                                                                                --    ==--  ==  --==  ....--  ..        --      ..
                                                                                  ==  cc  ==----    ..            --
                                                                      ..        ==                cc....==  ..
                                                                      ..      ==            --        ..                      --    ..
                                                                          ..                              --        --        ..
                                                                      ..--                      --                  ..      ..      ..
                                                                    ..    ..          ....                    ..        ..    ====
                                                                            ..            --      ..                      ----
                                                                                  --              ..          --        ==....
                                                                          ----            ..--                            ..==
                                                                        --            ..                                ----
                                                                              ..          --              ....  ..  --    cc..--
                                                                                    --  --                                  cc..
                                                                            ..                                      --        ......
                                                                            --      ..      ..            ..            ..  ..
                                                                      ..    ..          ----  ..    ..          ..    ..
                                                                    ..    ..                        ..          ..  ..
                                                                          --..                ..          ..
                                                                            ==      --                  --  ..      --              --
                                                                    ..    ----cc        --        --....        --      ....
                                                                          ==        ..      --    ..        --    --            ..
                                                                            ..--        ==  ==              --  ..  --        --
                                                                                ..cc----  ------            ..==cccc==....==  ..  --
                                                                        ..            ..cc--==..                ..==  ==
                                                                                --  ==cc  ----==            ..    --==
                                                                                  ----==..  cc  cc        ..    ==--          --
                                                                      ..    ..      ..--      --==                      --
                                                                            ..              --    --..  --  --
                                                                    ....                  ..    ..    --




Simulation Flow
Initialization: The grid is initialized with random values in the center.
Grid Updates: The grid is updated using the compute_grid_diff() function, which calculates the change in state for each cell based on the neighboring cells' values.
Boundary Conditions: The grid updates use periodic boundary conditions, meaning that cells on the edges interact with cells on the opposite side of the grid.
Output: After each update, the grid is displayed using the defined intensity levels.
Mathematical Model
The simulation implements a simplified version of reaction-diffusion systems with custom parameters. Key functions involved in the simulation include:

sigma(x, a, alpha): A logistic function used for calculating reaction dynamics.
s(n, m): Combines two different reactions for the final update.
compute_grid_diff(): Computes the difference between the current state and the next state for all grid cells.
apply_grid_diff(): Applies the computed differences to the grid, clamping values between 0 and 1.
Contributing
Contributions are welcome! If you have ideas to improve the simulation, or if you’d like to add new features or fix bugs, feel free to fork the repository and submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgements
Special thanks to Lenia for inspiring the model used in this simulation.
OpenGL and other libraries may be used in further developments of this project for enhanced graphics.
