demo_fr025remix
===============
This project is supposed to be a remake of the notorious demo from farbrausch called fr-025: the.popular.demo

recognized issues
-----------------
- Using sf::Music results in out-of-sync audio (~200ms).
- Using sf::Sound / sf::SoundBuffer results in ridiculously long loading time (~20s).
- Wavefront .obj file loading is limited to vertices and normals. Therefore there are no materials and everything has the same color.

TODO
----
- Further .obj support
- Actual implementation of engine classes (Animation, Duplicator, Scene)
- Light control
