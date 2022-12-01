# 42_Fractol
This project aims to use 2D programming to discover the psychedelic universe of fractals.

## Example

## Expected Result

## MinilibX
This project use the "MinilibX" library.  
The installation process include the compilation from sources, the linking and the creation of the static library.

Some external packages can be necessary, depending on your OS: https://github.com/42Paris/minilibx-linux  

A MacOs version is included in the "lib" folder. In this case, update the makefile for "minilibx-macos".

## Install
Create or update the "fractol" program from sources.
```
make
```

## Reinstall
Recompile completely the program.
```
make re
```

## Clean
Delete object files created during installation.
```
make clean
```

## Uninstall
Delete object files but also the compiled program.  
It will not affect the source code.
```
make fclean
```

## Usage
```
./fractol mandelbrot
```

## Fractals list
```
./fractol -l
```

## MAN (complete user manual)
```
./fractol -h
```

## Screenshots

More screenshots are availables in the "screens" folder.

## Notes
I recommand to use the "clang" compiler because "gcc" generates linking error with the minilibx.  
Check that clang compiler is installed on your system.

If there is permission issue:
```
chmod 774 lib/minilibx-linux/configure
```

## Keywords
2D programming  
Optimization techniques  
Complex numbers  
Mathematical equations  
Fractals  
