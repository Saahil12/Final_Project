# Final_Project

## Goal  
try to recreate a version of Space Invaders using Qtcreator and C++  

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
    Site I used to get spacebg.jpeg
  

## 10C implementations  
  * #### Iterators, Generic Algorithms, and Lambda Functions: 
    I used the **std::for_each** algorithm to traverse a list with iterators and applied a lambda function to each element in the slots below:    
     * used in defend() slot in wall.cpp     
     * used in defend() slot in wall2.cpp     
    
    Unfortunately, the combination of Iterators, Generic Algorithms, and Lambda functions in the slots below caused the program to crash unexpectedly and unpredictably. Thus, I have commented that code out and used just **iterators** below:  
     * used in move() slot in enemy.cpp to traverse through a List  
     * used in move() slot in bullet.cpp to traverse through a List  
     * used in move() slot in bullet_enemy2.cpp to traverse through a List  
  
## Journal 
  Commit: Added a rect object to scene  
  
  <img width="509" alt="screen shot 2018-05-16 at 10 03 36 am" src="https://user-images.githubusercontent.com/38049808/40211124-a761534e-59fd-11e8-9449-00a6badaa3d7.png"> <br />
<br />  
  
  Commit: Rect object responds to key events <br />
  
  <img width="468" alt="screen shot 2018-05-16 at 10 49 37 am" src="https://user-images.githubusercontent.com/38049808/40211264-8fee1dd6-59fe-11e8-95e8-9727502554c1.png"> <br />
<br />

  Commit: Rect shots smaller rect bullets <br />
  
  ![img_8557](https://user-images.githubusercontent.com/38049808/40869721-8b00b2b6-65d4-11e8-8140-94194d341ad2.jpg) <br />
<br />

  Commit: Created Enemies that spawn <br />
  
  <img width="624" alt="screen shot 2018-05-24 at 8 52 24 pm" src="https://user-images.githubusercontent.com/38049808/40525393-a325d7f4-5f94-11e8-986c-6d4c64a40ade.png"> <br />
<br />

  Commit: Created Health and Score <br />
  Commit: Added pictures and backgrounds <br />
  
 <img width="504" alt="screen shot 2018-06-01 at 7 40 47 pm" src="https://user-images.githubusercontent.com/38049808/40869669-19299eaa-65d4-11e8-8036-f0dba2b3a5cf.png"> <br />
<br /> 

  Commit: Added Enemy2 <br />  
<img width="504" alt="screen shot 2018-06-04 at 1 01 58 pm" src="https://user-images.githubusercontent.com/38049808/40938788-a4b0ddba-67f7-11e8-83c6-97486d42758b.png"> <br />
<br />

  Commit: Added defense wall <br />
<img width="504" alt="screen shot 2018-06-11 at 6 19 45 pm" src="https://user-images.githubusercontent.com/38049808/41264929-5600f9d6-6da4-11e8-99e4-05189a2dfa4b.png"> <br />
<br />
  
  Commit: Added Main Menu <br />
<img width="504" alt="screen shot 2018-06-17 at 6 33 25 pm" src="https://user-images.githubusercontent.com/38049808/41514615-4526310e-725d-11e8-94d4-bde8f5d2ab5f.png"> <br />
<br />
  
  
