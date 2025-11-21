import pygame
import random
import pandas 
# Initialize Pygame
pygame.init()

# Set up the screen
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption('Pong')

# Colors for the paddles and ball
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)

# Create the paddle objects
paddle_left = pygame.rect.Rect((400, 200), (200, 40))
paddle_right = pygame.rect.Rect((800, 200), (200, 40))

# Create the ball object
ball = pygame.rect.Rect((200, 200), (40, 40))

# Ball speed and direction
speed = 5
direction = 0

# Ball color
BALL_COLOR = (255, 0, 0)

# Function to handle user input
def on_key_press(key):
    if key == pygame.K_UP:
        direction += 1
    elif key == pygame.K_DOWN:
        direction -= 1
    elif key == pygame.K_LEFT:
        speed -= 1
    elif key == pygame.K_RIGHT:
        speed += 1

# Function to update the game
def update():
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

        if event.type == pygame.KEYDOWN:
            on_key_press(event.key)

    # Update the ball position
    ball.x += speed * direction
    ball.y += speed * direction

    # Check if the ball hits the paddles
    if ball.x >= 800:
        ball.x = 0
    if ball.x <= 0:
        ball.x = 800

    if ball.y >= 600:
        ball.y = 0
    if ball.y <= 0:
        ball.y = 600

    # Draw the game
    screen.fill(GREEN)
    pygame.draw.rect(screen, BLACK, paddle_left)
    pygame.draw.rect(screen, BLACK, paddle_right)

    screen.fill(WHITE)
    pygame.draw.circle(screen, BALL_COLOR, ball.center, 4)

    pygame.display.update()

# Main game loop
while True:
    update()
    pygame.display.set_caption('Pong')
    pygame.display.update()