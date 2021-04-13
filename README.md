# CppProject9_FireFly_synchronization
 

This is my 9th Project

Brief description - 
   Decided to try making some firefly synchronization.
   Fireflys flash and incluence each other to synchronize.

Preview
![ezgif com-gif-maker (3)](https://user-images.githubusercontent.com/67654528/114602842-fb47ae00-9c8e-11eb-80da-9d6918ce10e4.gif)


Full video on Youtube -- https://youtu.be/nWG7fOTy0w0

This uses the SFML library. -- I think its the 64bit Visual Studio 15 one.

Setup - (This is for myself in the future)

Go into Project Properties- Select all Configurations In C++ -> Additional Include Dicts add "c:\SFMLVS\INCLUDE" In Linker -> Additional Library Dicts "c:\SFMLVS\lib" In Linker, Linker Input -> Additional Dependencies "sfml-window.lib;sfml-system.lib;sfml-graphics.lib;sfml-audio.lib;sfml-network.lib;"

Apply <- Go into Debug Configuration In Linker, Linker Input -> "sfml-window-d.lib;sfml-system-d.lib;sfml-graphics-d.lib;sfml-audio-d.lib;sfml-network-d.lib;"

After that get SFMLVS Bin .dlls and add into solution with CPP files. --> Run
