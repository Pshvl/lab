import pygame

class Button:
    def __init__(self, text, pos):
        self.text = text
        self.pos = pos
        self.font = pygame.font.Font(None, 36)
        self.rect = pygame.Rect(self.pos, (200, 50))

    def draw(self, screen, font):
        pygame.draw.rect(screen, (0, 255, 0), self.rect)
        text_surface = font.render(self.text, True, (0, 0, 0))
        screen.blit(text_surface, (self.pos[0] + 50, self.pos[1] + 10))

    def is_clicked(self, pos):
        return self.rect.collidepoint(pos)
