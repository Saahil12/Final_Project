# Space Attack
<br />

## Summary  
This project uses Qtcreator and C++ to create a video game as a final project for Professor Salazar's Pic 10C class at UCLA
<br />
**Youtube link** : https://youtu.be/JGPBBT1KMjM

## Instructions
Protect yourself and don't let any invaders by you! Use spacebar to shoot and left/right arrow keys to move. The viscous green invaders take 3 shots to kill while the soarin red invaders only take 1! However, be careful because the red invaders will fire back! Each segment of your defensive wall can take 2 hits before being completely destroyed. Your health starts off at 3 and decreases every time a green invader gets past you, a green invader hits you, or a red invaders bullet hits you. See how long you can protect your galaxy!!
<br />

##  References
  * http://doc.qt.io/archives/qt-4.8/index.html  
    Used this Qt site to learn and understand member functions of certain standard classes and objects
  * https://www.youtube.com/watch?v=8ntEQpg7gck&list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy&index=2  
    Used this Qt game tutorial to get familiar with Qt and its classes, more specifically, QPixMapItem, QGraphicsRectItem, QKeyEvent, QMediaPlayer, and QGraphicsTextItem. 
  * http://moreinfo.thebigboss.org/moreinfo/spaceinvadersbootlogo.php  
    Site I got enemy.png & enemy2.png. I used remove backround in PowerPoint and adjusted the size before adding as an image resource to Qt  
  * https://commons.wikimedia.org/wiki/File:Space_invaders.character.jpeg  
    Site I used to get player.png picture. I used remove backround in PowerPoint and adjusted the size before adding as an image resource to Qt
  * http://www.clker.com/cliparts/H/Z/0/r/m/o/tall-blue-rectangle-md.png  
    Site I used to get wall1.png. I used PowerPoint to change the color and adjusted the size before adding as an image resource to Qt. Also used PowerPoint to change features of this image for wall2.png.  
    <br />
    bullet.png and enemy2_bullet.png were simply created from PowerPoint shapes  
    <br />
  * https://www.pond5.com/stock-footage/23768280/simple-star-space-background-effect.html  
    Site I used to get spacebg.jpeg, the background image  
  * http://www.classicgaming.cc/classics/space-invaders/sounds  
    Site I used for all audio files   
<br />  

## 10C implementations  
  * #### Iterators, Generic Algorithms, and Lambda Functions: 
    I used the **std::for_each** algorithm to traverse a list with iterators and applied a lambda function to each element in the slots below:    
     * used in defend() slot in wall.cpp     
     * used in defend() slot in wall2.cpp     
    
    Unfortunately, the combination of Iterators, Generic Algorithms, and Lambda functions in the slots below caused the program to crash unexpectedly and unpredictably. Thus, I have commented that code out and used just **iterators** below:  
     * used in move() slot in enemy.cpp to traverse through a List  
     * used in move() slot in bullet.cpp to traverse through a List  
     * used in move() slot in bullet_enemy2.cpp to traverse through a List  
 
 * #### RAII  
   Not all objects have been deleted or need to be deleted because Qt objects are RAII ready. They "clean up after themselves" when they go out of scpe.
 <br />
 
## Journal 
  **Commit:** Added a rect object to scene  
  **Progress:** I had just started using Qt and didn't have a project idea yet so I used youtube videos (2nd reference) to understand the layout, slots, signals, and objects. Here I was experimenting with QGraphicsRectItem. 
  <img width="509" alt="screen shot 2018-05-16 at 10 03 36 am" src="https://user-images.githubusercontent.com/38049808/40211124-a761534e-59fd-11e8-9449-00a6badaa3d7.png"> <br />
<br />  
  
  **Commit:** Rect object responds to key events <br />
  **Progress:** At this point I continued to use youtube tutorials to get familiar with QKeyEvent and focusing at on one object at a time. Now I knew I wanted to create a video game where the user was able to move the player  
  <img width="468" alt="screen shot 2018-05-16 at 10 49 37 am" src="https://user-images.githubusercontent.com/38049808/40211264-8fee1dd6-59fe-11e8-95e8-9727502554c1.png"> <br />
<br />

  **Commit:** Rect shots smaller rect bullets <br />
  **Progress:** Here I got familiar with QTimer and with creating my own slots. AFter being able to make my rect shoot, I knew I wanted to create a space invaders type of game.  
  ![img_8557](https://user-images.githubusercontent.com/38049808/40869721-8b00b2b6-65d4-11e8-8140-94194d341ad2.jpg) <br />
<br />

  **Commit:** Created Enemies that spawn <br />
  **Progress:** I knew I wanted enemies to spawn througout the game so I had them appear from the top and move down the screen. I decided to create as much of the game I had in mind with QGraphicsRectItem because I was unsure of how to add pictures yet.  
 <img width="504" alt="screen shot 2018-05-24 at 8 52 24 pm" src="https://user-images.githubusercontent.com/38049808/41580631-67a65c24-7350-11e8-84da-03f7f8f08acd.png"> <br />
<br />

  **Commit:** Created Health and Score <br />
  **Commit:** Added pictures and backgrounds <br />
  **Progress:** I did some research on QGraphicsTextItem so that I could display the score and health. I also felt I was ready to add pictures so I did research on QPixMapItem and resource files. I changed all my rect items to pictures I found online (references above). Lastly, I learned about QMediaPlayer and added sounds throughout the interactions of the game.  
 <img width="504" alt="screen shot 2018-06-01 at 7 40 47 pm" src="https://user-images.githubusercontent.com/38049808/40869669-19299eaa-65d4-11e8-8036-f0dba2b3a5cf.png"> <br />
<br /> 

  **Commit:** Added Enemy2 <br />
  **Progress:** I knew my game was going in the right track but it felt to easy and basic to me. Thus, I decided to add another enemy that moves across the screen and fires back.  
<img width="504" alt="screen shot 2018-06-04 at 1 01 58 pm" src="https://user-images.githubusercontent.com/38049808/40938788-a4b0ddba-67f7-11e8-83c6-97486d42758b.png"> <br />
<br />

  **Commit:** Added defense wall <br />
  **Progress:** At this point I wanted to add more unique touches to the game so I decided to make a wall that can take two hits before being completely destoyed. I started to implement topics we were going through in class such as iterators, lambda functons, and generic algorithms.  
<img width="504" alt="screen shot 2018-06-11 at 6 19 45 pm" src="https://user-images.githubusercontent.com/38049808/41264929-5600f9d6-6da4-11e8-99e4-05189a2dfa4b.png"> <br />
<br />
  
  **Commit:** Added Main Menu <br />
  **Progress:** I felt done with my game but I didn't like how it jumped straight into the game. So I did some research online on how to make buttons simply through QGraphicsRectItems and QGraphicsTextItem for my "main menu".  
<img width="504" alt="screen shot 2018-06-17 at 6 33 25 pm" src="https://user-images.githubusercontent.com/38049808/41514615-4526310e-725d-11e8-94d4-bde8f5d2ab5f.png"> <br />
<br />
  
  
