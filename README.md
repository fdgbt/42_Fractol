# 42_Fractol
This project aims to use 2D programming to discover the psychedelic universe of fractals.

## Example
Created by Benoît Mandelbrot in 1974 from the Latin "fractus", which means "broken", "irregular", a fractal figure is a mathematical object, such as a curve or a surface, whose structure is invariant whatever the change of scale.  

Many natural phenomena – such as the appearance of romanesco cabbage – have rough fractal shapes.
![Romanesco_broccoli_(Brassica_oleracea)](https://user-images.githubusercontent.com/52746061/205169866-e702e9a5-aa2b-4736-a4a0-c6c281553600.jpg)

https://en.wikipedia.org/wiki/Fractal

## Expected Result
The program includes 9 different and interesting fractals.  
They are all configurable in depth, with colors customization, mathematical variables, interaction modes, advanced zoom, etc.  

Look for the MAN to see all the possibilities and commands!

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
1) Mandelbrot		
2) Julia		
3) Burning_ship		
4) Multibrot		
5) Buddhabrot		
6) Newton		
7) Koch		
8) Sierpinski		
9) Barnsley

## MAN (complete user manual)
```
./fractol -h
```

## Screenshots
![mandelbrot_neutral_ssaa8](https://user-images.githubusercontent.com/52746061/205167885-e67f2d7e-cbc0-4ede-bc6e-d5ea0883dc8e.png)  
![julia_fairy_ssaa8](https://user-images.githubusercontent.com/52746061/205167784-4625719b-3d40-48dc-9511-55fa1e99b1c9.png)  
![julia_hsv_ssaa8](https://user-images.githubusercontent.com/52746061/205167823-20f8035c-f357-46df-8755-3424a8f39510.png)  
![burning_ship_fire_ssaa8](https://user-images.githubusercontent.com/52746061/205167719-3b9fd6aa-ea60-4842-8dd3-a985ca0d37dd.png)  
![barnsley_camo_ssaa8](https://user-images.githubusercontent.com/52746061/205167631-c36faa2e-1400-479d-846e-af0ff666d05b.png)  
![buddha_nasa_ssaa8](https://user-images.githubusercontent.com/52746061/205167666-e8d8e991-df9c-4440-8967-306b93b0eddc.png)  

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
Multi-Threading 
Complex numbers  
Mathematical equations  
Fractals  
