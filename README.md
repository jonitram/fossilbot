# Pokemon Box Fossil Restoration Bot

As long as the in-game preconditions are met before plugging in the device, plugging the Arduino directly into the Switch through a USB Type B to USB Type C Cable should enable the bot to start restoring the specified number of fossil pokemon

## In-Game Information

### Preconditions

- When you press the `a button` you initiate dialogue with the fossil restoration lady
- You have enough fossil parts to restore the specified amount of fossils
- It is recommended that you redirect your PC Box cursor to a series of empty boxes if you are going to be restoring a lot of pokemon

## Setting up the Arduino

- Disclaimer: These instructions were written for Mac OSX in the context of an Arduino with an atmega16u2 chip
- Change the `fossils` variable to the number of fossil pokemon you would like restored at the top of `instructions.h` before making and flashing `Joystick.hex` to the Arduino
- Currently, the bot restores a `Fossilized Fish` and a `Fossilized Drake` to form the pokemon `Dracovish`. This can be changed by editing the `move_down` commands in `instructions.h` when selecting which fossil should be restored

### Dependencies and Compiling

- Install dfu-programmer through homebrew with:

    `brew install dfu-programmer`
- To compile this project you need AVR GCC Compiler and Tools. This can be installed through homebrew with:

    `brew tap osx-cross/avr`

    followed by

    `brew install avr-gcc`
- Download the LUFA library through this [link](http://www.fourwalledcubicle.com/LUFA.php) and put it in this directory
- Make sure the `LUFA_PATH` inside the `makefile` points to the LUFA subdirectory that you just created inside this directory
- Ensure that the `makefile` setting for `MCU` is set to `MCU = atmega16u2` and compile by typing `make`

### Putting the Arduino in DFU Mode

- Plug the Arduino into a computer
- Put the Arduino in DFU mode if it is not already by bridging the reset pin with the ground
- If necessary, ensure the Arduino is in DFU mode by typing:

    `sudo dfu-programmer atmega16u2 get ID1`

### Flashing onto the Arduino

- Navigate to the folder containing the `.hex` file you are flashing onto the Arduino
- In this case, the `.hex` file to be flashed onto the Arduino is called `Joystick.hex` generated by the `makefile`
- Follow these commands to flash the `.hex` file:

    `sudo dfu-programmer atmega16u2 erase`

    `sudo dfu-programmer atmega16u2 flash <.hex file>`

    `sudo dfu-programmer atmega16u2 reset`

- If you receive this error:

    `dfu-programmer: no device present.`

    but your Arduino is plugged in and the lights are on then you most likely need to put the Arduino into DFU mode by bridging its reset and ground pins