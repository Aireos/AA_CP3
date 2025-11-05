# AKA Pygame Notes

import pygame
import random
import math
import time
from pygame import mixer

pygame.init()

user_screen_info = pygame.display.Info()
max_x = user_screen_info.current_w
max_y = user_screen_info.current_h
screen = pygame.display.set_mode((max_x, max_y))

pygame.display.set_caption("Space Invadors")

pygame_icon = pygame.image.load('Python/Personal/space_invadors/resources/ufo-1.png')
pygame.display.set_icon(pygame_icon)

class Player:
    def __init__(self, x=max_x/2, change = 0, shoot = False, score = 0):
        self.image = pygame.image.load('Python/Personal/space_invadors/resources/spaceship.png')
        self.x = x
        self.y = max_y - self.image.get_height()
        self.change = change
        self.shoot = shoot
        self.score = score

    def player_set(self):
        screen.blit(self.image, (self.x, self.y))

    def move(self):
        self.x += self.change
        if self.x > max_x-self.image.get_width():
            self.x = max_x-self.image.get_width()
        if self.x < 0:
            self.x = 0

speed = 5
running = True

class Enemy:
    def __init__(self, x, y=0, change = speed):
        self.image = pygame.image.load('Python/Personal/space_invadors/resources/alien.png')
        self.x = x
        self.y = y
        self.change = change

    def enemy_set(self):
        screen.blit(self.image, (self.x, self.y))

    def move(self):
        self.x += self.change
        if self.x > max_x-self.image.get_width():
            self.change = -speed
            self.x = max_x-self.image.get_width()
            self.y += self.image.get_height()
        if self.x < 0:
            self.change = speed
            self.x = 0
            self.y += self.image.get_height()
        if self.y > max_y-self.image.get_height():
            return(False)
        else:
            return(True)
    
    def is_hit(self, bullet):
        distance = math.sqrt((self.x - bullet.x)**2 + (self.y - bullet.y)**2)
        if distance < ((self.image.get_width())/2)+((bullet.image.get_width())/2):
            return True
        return False
    
class Bullet:
    def __init__(self,x=0,y=0, change = speed*2):
        self.state = "ready"
        self.x = x
        self.y = y
        self.change = change
        self.image = pygame.image.load('Python/Personal/space_invadors/resources/bullet.png')
        self.rotation = pygame.transform.rotate(self.image,90)

    def move(self):
        self.y -= self.change
        if self.y < 0:
            self.state = "ready"
    
    def bullet_set(self):
        screen.blit(self.image, (self.x, self.y))

class Button:
    def __init__(self,x,y,surface):
        self.x = x
        self.y = y
        self.surface = surface
        self.rect = self.surface.get_rect(center=(x, y))

    def draw(self):
        position = pygame.mouse.get_pos()
        if self.rect.collidepoint(position):
            pass
        screen.blit(self.surface, self.rect.topleft)

player = Player()
enemys = [Enemy(0)]
bullet = Bullet()
level = 1
game_over_state = False

background = pygame.image.load('Python/Personal/space_invadors/resources/background-1.jpg')
backround = pygame.transform.scale(background, (max_x, max_y))

game_over_font = pygame.font.Font('Python/Personal/space_invadors/resources/Sterion-BLLld.ttf',64)
game_over_text = game_over_font.render(f"Game Over", True, (255,255,255))

score_font = pygame.font.Font('Python/Personal/space_invadors/resources/Sterion-BLLld.ttf',32)

restart_font = pygame.font.Font('Python/Personal/space_invadors/resources/Sterion-BLLld.ttf',32)
restart_text = restart_font.render(f"Restart", True, (255,255,255))

exit_font = pygame.font.Font('Python/Personal/space_invadors/resources/Sterion-BLLld.ttf',32)
exit_text = exit_font.render(f"Exit", True, (255,255,255))

restart_button = Button(max_x/2, max_y/2 + 50, restart_text)

exit_button = Button(max_x/2, max_y/2 + 200, exit_text)

mixer.music.load("Python/Personal/space_invadors/resources/background.wav")
mixer.music.play(-1)

while running:

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                running = False
        
        if not game_over_state:
            keys = pygame.key.get_pressed()
            if event.type == pygame.KEYDOWN:
                if keys[pygame.K_LEFT]:
                    player.change = -speed*1.5
                if keys[pygame.K_RIGHT]:
                    player.change = speed*1.5
                if keys[pygame.K_SPACE]:
                    if bullet.state == "ready":
                        bullet.x = player.x + player.image.get_width() / 2 - bullet.image.get_width() / 2
                        bullet.y = player.y
                        mixer.Sound("Python/Personal/space_invadors/resources/laser.wav").play()
                        bullet.state = "fired"
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    player.change = 0
        else:
            if event.type == pygame.MOUSEBUTTONDOWN:
                if restart_button.rect.collidepoint(event.pos):
                    player = Player()
                    enemys = [Enemy(0)]
                    bullet = Bullet()
                    level = 1
                    game_over_state = False
                    mixer.music.play(-1)
                if exit_button.rect.collidepoint(event.pos):
                    running = False

    screen.blit(background, (0, 0))

    if not game_over_state:
        player.move()
        for enemy in list(enemys):
            if enemy.move() == False:
                game_over_state = True

            if bullet.state == "fired": 
                if enemy.is_hit(bullet):
                    bullet.state = "ready"
                    mixer.Sound("Python/Personal/space_invadors/resources/explosion.wav").play()
                    player.score += 1
                    enemys.remove(enemy)
                    if enemys == []:
                        level += 1
                        for i in range(level):
                            enemys.append(Enemy(i * 70))
            enemy.enemy_set()

        if bullet.state == "fired": 
            bullet.move()
            bullet.bullet_set()

        score_display = score_font.render(f"Score: {player.score}", True, (255,255,255))
        screen.blit(score_display, (10, 10))

        player.player_set()

    else:
        game_over_rect = game_over_text.get_rect(center=(max_x/2, max_y/2 - 50))
        screen.blit(game_over_text, game_over_rect.topleft)
        restart_button.draw()

        exit_rect = exit_text.get_rect(center=(max_x/2, max_y/2 - 200))
        screen.blit(exit_text,exit_rect.topleft)
        exit_button.draw()

    pygame.display.flip()

pygame.quit()