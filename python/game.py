import pygame
import random

# Initialize the game engine
pygame.init()

# Set up the game screen
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Pong")

# Set up the colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# Set up the player objects
player1 = pygame.Rect(100, 300, 80, 10)
player2 = pygame.Rect(600, 300, 80, 10)

# Set up the ball
ball = pygame.Rect(300, 300, 10, 10)

# Set up the speed of the ball
ball_speed_y = 10

# Game loop
running = True
while running:

    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update the ball's position
    ball.x += ball_speed_y
    ball.y += -ball_speed_y

    # Keep the ball within the screen
    if ball.top > 600 or ball.bottom < 0:
        ball_speed_y *= -1

    # Check for collisions
    if pygame.sprite.collide_rect(ball, player1) or pygame.sprite.collide_rect(ball, player2):
        ball_speed_y *= -1

    # Draw the screen
    screen.fill(BLACK)
    screen.blit(player1, (100, 300))
    screen.blit(player2, (600, 300))
    screen.blit(ball, ball.x, ball.y)

    # Update the display
    pygame.display.update()

# Quit the game
pygame.quit()