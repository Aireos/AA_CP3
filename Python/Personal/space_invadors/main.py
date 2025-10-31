# AKA Pygame Notes

import pygame
import random

pygame.init()

user_screen_info = pygame.display.Info()
max_x = user_screen_info.current_w
max_y = user_screen_info.current_h
screen = pygame.display.set_mode((max_x, max_y))

pygame.display.set_caption("Space Invadors")

pygame_icon = pygame.image.load('Python/Personal/space_invadors/resources\\ufo-1.png')
pygame.display.set_icon(pygame_icon)

class Player:
    def __init__(self, x=max_x/2, change = 0):
        self.image = pygame.image.load('Python/Personal/space_invadors/resources\\spaceship.png')
        self.x = x
        self.y = max_y - self.image.get_height()
        self.change = change

    def player_set(self):
        screen.blit(self.image, (self.x, self.y))

    def move(self):
        self.x += self.change
        if self.x > max_x-self.image.get_width():
            self.x = max_x-self.image.get_width()
        if self.x < 0:
            self.x = 0

class Enemy:
    def __init__(self, y, x=max_x/2, change = 0):
        self.image = pygame.image.load('Python/Personal/space_invadors/resources\\alien.png')
        self.x = x
        self.y = max_y - self.image.get_height()
        self.change = change

    def player_set(self):
        screen.blit(self.image, (self.x, self.y))

    def move(self):
        self.x += self.change
        if self.x > max_x-self.image.get_width():
            self.x = max_x-self.image.get_width()
        if self.x < 0:
            self.x = 0

player = Player()

running = True

sensitivity = 1

while running:

    for event in pygame.event.get():

        keys = pygame.key.get_pressed()

        if event.type == pygame.QUIT:
                running = False
        
        if event.type == pygame.KEYDOWN:

            if keys[pygame.K_LEFT]:
                player.change = -sensitivity

            if keys[pygame.K_RIGHT]:
                player.change = sensitivity
        
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                player.change = 0
            
    player.move()

    player.player_set()

    pygame.display.flip()