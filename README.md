Pengine2D
---------

Notes
=====

* the scenes used in a game should each be a class that inherit from Scene
* Scene should have a virtual void function init that must be overridden
* thus Scene will be abstract
* inheritence should be public a la class Scene1: public Scene {
* probably everything should be in the same namespace ("Pengine2D"?)
* game loop
    - Game should have an Input object attached to it that its child scenes can query
    - Game should have a flag indicating when its quitting
    - main will have a loop checking the flag
    - each scene will have a game loop that
        - updates game objects according to input
        - repaints its texture
        - tells the Game\'s GameManager when the scene is over and why (victory, death)

Short\-term TODO
===============

* add a render method to HitBox and use it in PrimitiveRect and Sprite
* control frame rate
* create GameObject subclass for Background
* create GameObject subclass Sprites
* create GameObject subclass Hero
* move hero according to input

Long\-term TODO
===============
* hit boxes
* create GameObject subclass for Tiled Tiles
* implement Scene texture layers for its GameObjects
