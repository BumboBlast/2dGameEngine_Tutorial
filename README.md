
17May:	Added first game files, barest bones of a not-very-boney skeleton of a game loop.

19May:	Learning how to manage textures (png's)!!!
			
			- First thing, when creating textures, need to create a surface.
			- Rendering:  Using the painter's algorithm (first thing "painted" in background)

19May:	Capping Framerate

			- we will get our current running time when we first start the frame, 

20May:	Texture Manager, to make loading textures much easier

20May:	Created GameObject Class!!

			- Rather than keep updating all objects in the main, game class,
			- Each object will have its own updates with its own specific behaviours.


21May:	Some Refactoring, and added Map class!
			
			- Replace the game class's private renderer with a static renderer
			- Refactoring includes: putting the renderer (part of game)
			- into texture manager class, so i only have to pass in filepath, and initial positon as arguments

			- the 'map' holds grass water and dirt, and will be stored in a 2-d integer array just to get it working.

			QUESTION: Can i replace the array copying for-loop in Map.cpp with just "arr1 = arr2;"