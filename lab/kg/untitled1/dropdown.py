import pygame

class Dropdown:
    def __init__(self, items, pos):
        self.items = items
        self.pos = pos
        self.font = pygame.font.Font(None, 36)
        self.selected_item = self.items[0]
        self.rect = pygame.Rect(self.pos, (200, 50))

    def draw(self, screen, font):
        pygame.draw.rect(screen, (255, 0, 0), self.rect)
        text_surface = font.render(self.selected_item, True, (0, 0, 0))
        screen.blit(text_surface, (self.pos[0] + 50, self.pos[1] + 10))

    def get_selected_item(self):
        return self.selected_item

    def is_clicked(self, pos):
        return self.rect.collidepoint(pos)

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN and self.rect.collidepoint(event.pos):
            # Логика для открытия/закрытия выпадающего списка и выбора элемента
            pass
