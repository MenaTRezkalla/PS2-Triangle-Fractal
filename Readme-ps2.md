# PS2: Triangle Fractal

## Contact
Name: Mena Rezkalla
Section: 201

Partner Name: (No Partner)
Partner Section: (No Section)

Time to Complete: 3 Days

## Description
Draws a variation of the sierpinski triangle fractal. The program takes in 4 arguments, with R and colorful being optional. 
L, the length of the initial triangle, 
N, the depth of the fractal, 
R, the rotation of the initial triangle in degrees, and lastly, 
colorful. When colorful is set to 1, each triangle will be a different color for it's depth. If colorful is set to 0, the triangles will just have white outlines.

### Features
I decided to create triangles and make their origin points at one of their points, so rotating the child triangles would be really easy.
I used a vector to store all the triangles so that SFML could write them to the screen.
For my recursion, I first create a triangle, then for each point for that triangle, I create another one with half of the original length at that point,
and a specified rotation based on the point that it was being created.

### Issues
I had difficulty with scaling the window to fit the fractal. 
There is something that doesn't work, if you were to use the rotation parameter, the window is unable to adjust to fit the rotated fractal.
I don't know how to fix this.

### Extra Credit
I added a rotation parameter that affects the rotation of the initial triangle in degrees, 
and a colorful parameter. When colorful is set to 1, each triangle will be a different color for it's depth. 
If colorful is set to 0, the triangles will just have white outlines.

## Pair Programming
It didn't, since I decided to do it myself.

## Acknowledgements
Google
SFML Documentation

