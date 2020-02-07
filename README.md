# 42spaceShooter
42 ft_retro - C++ course's 1st weekend group project <br></br>
Collaborate with another student (Alex-https://github.com/NotHawthorne) <br></br>
to develop a vertical scrolling shooting game from scratch within 48hours

# Usage:
> ## To start build and start the game:<br></br>
> make - creates the executable "ft_retro"<br></br>
> make clean - removes *.o files<br></br>
> ./ft_retro to run the game

> make fclean - does clean^ and removes executable<br></br>
> make re - does fclean && make<br></br>

> ## In Game control:<br></br>
> arrow keys- spaceship movement<br></br>
> c - shoots bullets<br></br>

# Title Screen: 
<img src="https://github.com/yakuseishou/42spaceShooter/blob/master/markdownIMG/Title.png" alt="title page" width="50%" height="40%" style="float: inline-end; margin-left: 10%;"/><br></br>
# Menu:
<img src="https://github.com/yakuseishou/42spaceShooter/blob/master/markdownIMG/Menu.png" alt="title page" width="50%" height="40%" style="float: inline-end; margin-left: 10%;"/><br></br>
# GameOver:
<img src="https://github.com/yakuseishou/42spaceShooter/blob/master/markdownIMG/GameOver.png" alt="title page" width="50%" height="40%" style="float: inline-end; margin-left: 10%;"/><br></br>
# GamePlay:
<img src="https://github.com/yakuseishou/42spaceShooter/blob/master/markdownIMG/InGame.png" alt="title page" width="40%" height="30%" style="float: left; margin-right: 2%;"/>
<img src="https://github.com/yakuseishou/42spaceShooter/blob/master/markdownIMG/PlayerBullet.jpg" alt="title page" width="40%" height="30%" style="float: left; margin-right: 2%;"/><br></br>

# Possible improvement in the future
1. Horizontal movement and spawm point needs update:<br></br>
Horizontal coordinate(x) uses only every 2-3 space cause column are thinner than row, which causes a delay feeling when moving left and right if kept at moving one space at a time. Changing player moving horizontally 2-3 space at a time will have to change enemy spawm and enemy movement also or it could create unkillable enemy due to player bullet will never be on the same column.
2. Improve GUI <br></br>
add color to start up/menu/gameOver screen<br></br>
add control key tips

3. Incorprate live stock/Bosses/special ability for player

4. Different area map

5. power up item
