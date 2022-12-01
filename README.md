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
Optimization techniques  
Complex numbers  
Mathematical equations  
Fractals  
