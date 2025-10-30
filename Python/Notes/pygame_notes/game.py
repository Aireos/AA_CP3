# AKA Pygame Notes

import pygame

pygame.init()

max_x = 1000
max_y = 1000
screen = pygame.display.set_mode((max_x, max_y))

pygame.display.set_caption("Pygame Tutorial")
pos_x = 100
pos_y = 100

while True:
    screen.fill((195, 115, 42))
    pygame.draw.circle(screen, (250,0,0), (pos_x, pos_y), 10)


    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

        if pygame.key.get_pressed():
            key = pygame.key.get_pressed()
        if key[pygame.K_a]:
            pos_x -= 10

        if key[pygame.K_d]:
            pos_x += 10
        
        elif key[pygame.K_w]:
            pos_y -= 10
        
        elif key[pygame.K_s]:
            pos_y += 10
        
        pos_y += 5
        
        if pos_y <= 0:
            pos_y = 0
        
        if pos_y >= max_y:
            pos_y = max_y

    
    pygame.display.flip()


# How do you set up pygame?
# pip install pygame-ce
# 

# What is the purpose of the "While running" loop?
# to run it until the user exits the program

# How do you create a screen in pygame?
# screen = pygame.display.set_mode((max_x, max_y))

# How are objects placed on the screen in pygame?
# 

# What events can I listen for in pygame? What do those events do?
# 

# How can I detect collision with pygame?
# 

# How do you add sounds in pygame?
# 