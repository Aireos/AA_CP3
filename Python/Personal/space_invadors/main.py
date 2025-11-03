# AKA Pygame Notes

import pygame
import random
import math

pygame.init()

user_screen_info = pygame.display.Info()
max_x = user_screen_info.current_w
max_y = user_screen_info.current_h
screen = pygame.display.set_mode((max_x, max_y))

pygame.display.set_caption("Space Invadors")

pygame_icon = pygame.image.load('Python/Personal/space_invadors/resources\\ufo-1.png')
pygame.display.set_icon(pygame_icon)

class Player:
    def __init__(self, x=max_x/2, change = 0, shoot = False):
        self.image = pygame.image.load('Python/Personal/space_invadors/resources\\spaceship.png')
        self.x = x
        self.y = max_y - self.image.get_height()
        self.change = change
        self.shoot = shoot

    def player_set(self):
        screen.blit(self.image, (self.x, self.y))

    def move(self):
        self.x += self.change
        if self.x > max_x-self.image.get_width():
            self.x = max_x-self.image.get_width()
        if self.x < 0:
            self.x = 0

speed = 2
running = True

class Enemy:
    def __init__(self, y=0, x=0, change = speed):
        self.image = pygame.image.load('Python/Personal/space_invadors/resources\\alien.png')
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
        if distance < self.image.get_width():
            pass

class Bullet:
    def __init__(self,x=0,y=0, change = speed):
        self.state = "ready"
        self.x = x
        self.y = y
        self.change = change
        self.image = pygame.image.load('Python/Personal/space_invadors/resources\\bullet.png')
        self.rotation = pygame.transform.rotate(self.image,90)

    def move(self):
        self.y -= self.change
        if self.y < 0:
            self.state = "ready"
    
    def bullet_set(self):
        screen.blit(self.image, (self.x, self.y))

player = Player()
enemy = Enemy()
bullet = Bullet()
level = 1

while running:

    screen.fill((0,0,0))

    for event in pygame.event.get():

        keys = pygame.key.get_pressed()

        if event.type == pygame.QUIT:
                running = False
        
        if event.type == pygame.KEYDOWN:

            if keys[pygame.K_LEFT]:
                player.change = -speed

            if keys[pygame.K_RIGHT]:
                player.change = speed
            
            if keys[pygame.K_SPACE]:
                if bullet.state == "ready":
                    bullet.x = player.x + player.image.get_width() / 2 - bullet.image.get_width() / 2
                    bullet.y = player.y
                    bullet.state = "fired"


        
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                player.change = 0

    player.move()
    running = enemy.move()
    if bullet.state == "fired": 
        bullet.move()
        bullet.bullet_set()

    player.player_set()
    enemy.enemy_set()

    pygame.display.flip()