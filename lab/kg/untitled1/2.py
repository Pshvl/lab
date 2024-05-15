import pygame
from pygame.locals import *
from self import self
import sys

class Button:
    """Create a button object."""
    def __init__(self, text, pos):
        self.text = text
        self.pos = pos
        self.font = pygame.font.Font(None, 36)
        self.image = self.font.render(self.text, True, (255, 255, 255))
        self.rect = self.image.get_rect(center=pos)

    def draw(self, screen):
        screen.blit(self.image, self.rect)

    def is_clicked(self, pos):
        return self.rect.collidepoint(pos)
class Text:
    """Create a text object."""
    self.shortcuts = {
    # (K_x, KMOD_LMETA): 'print("cmd+X")',
    # (K_x, KMOD_LALT): 'print("alt+X")',
    # (K_x, KMOD_LCTRL): 'print("ctrl+X")',
    # (K_x, KMOD_LMETA + KMOD_LSHIFT): 'print("cmd+shift+X")',
    # (K_x, KMOD_LMETA + KMOD_LALT): 'print("cmd+alt+X")',
    # (K_x, KMOD_LMETA + KMOD_LALT + KMOD_LSHIFT): 'print("cmd+alt+shift+X")',

        (K_f, KMOD_LMETA): 'self.toggle_fullscreen()',
        (K_r, KMOD_LMETA): 'self.toggle_resizable()',
        (K_g, KMOD_LMETA): 'self.toggle_frame()',
    }
    def __init__(self, text, pos, **options):
        self.text = text
        self.pos = pos
        self.fontname = None
        self.fontsize = 72
        self.fontcolor = Color('black')
        self.set_font()
        self.render()
        self.flags = RESIZABLE
        self.rect = Rect(0, 0, 640, 240)
        App.screen = pygame.display.set_mode(self.rect.size, self.flags)
        icon_image = pygame.image.load("1.png")
        pygame.display.set_icon(icon_image)
        pygame.display.set_caption("Пердел Рыгал Game")

    def set_font(self):
        """Set the Font object from name and size."""
        self.font = pygame.font.Font(self.fontname, self.fontsize)

    def render(self):
        """Render the text into an image."""
        self.img = self.font.render(self.text, True, self.fontcolor)
        self.rect = self.img.get_rect()
        self.rect.topleft = self.pos

    def draw(self):
        """Draw the text image to the screen."""
        App.screen.blit(self.img, self.rect)


class App:
    """Create a single-window app with multiple scenes."""

    def __init__(self):
        """Initialize pygame and the application."""
        pygame.init()
        flags = RESIZABLE
        App.screen = pygame.display.set_mode((640, 240), flags)
        App.t = Text('ЖОПА СИСЬСКИ СРАТЬ КОРЗИНКА', pos=(20, 20))


        App.running = True

    def run(self):
        """Run the main event loop."""
        while App.running:
            for event in pygame.event.get():
                if event.type == QUIT:
                    App.running = False

            App.screen.fill(Color('gray'))
            App.t.draw()
            pygame.display.update()

        pygame.quit()

    def toggle_fullscreen(self):
         """Toggle between full screen and windowed screen."""
         self.flags ^= FULLSCREEN
         pygame.display.set_mode((0, 0), self.flags)

    def toggle_resizable(self):
         """Toggle between resizable and fixed-size window."""
         self.flags ^= RESIZABLE
         pygame.display.set_mode(self.rect.size, self.flags)

    def toggle_frame(self):
         """Toggle between frame and noframe window."""
         self.flags ^= NOFRAME
         pygame.display.set_mode(self.rect.size, self.flags)

# class Scene:
#     """Create a new scene (room, level, view)."""


# class Demo(App):
#         id = 0
#         bg = Color('pink')
#
#      def __init__(self, *args, **kwargs):
#          # Append the new scene and make it the current scene
#          App.scenes.append(self)
#          App.scene = self
#          # Set the instance id and increment the class id
#          self.id = Scene.id
#          Scene.id += 1
#          self.nodes = []
#          self.bg = Scene.bg
#
#
#      def draw(self):
#          """Draw all objects in the scene."""
#          App.screen.fill(self.bg)
#          for node in self.nodes:
#             node.draw()
#          pygame.display.flip()
#
#
#      def __str__(self):
#          return 'Scene {}'.format(self.id)
#
#      def __init__(self):
#          super().__init__()
#
#          Scene(caption='Intro')
#          Text('Scene 0')
#          Text('Introduction screen the app')
#
#          Scene(bg=Color('yellow'), caption='Options')
#          Text('Scene 1')
#          Text('Option screen of the app')
#
#          Scene(bg=Color('green'), caption='Main')
#          Text('Scene 2')
#          Text('Main screen of the app')
#
#          App.scene = App.scenes[0]
class GameWindow:
    """Create a game window."""
    def __init__(self):
        self.screen = pygame.display.set_mode((800, 600))
        pygame.display.set_caption("Моя Игра")
        self.buttons = [Button("Играть", (400, 300)), Button("Настройки", (400, 400))]

    def run(self):
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    mouse_pos = pygame.mouse.get_pos()
                    for button in self.buttons:
                        if button.is_clicked(mouse_pos):
                            if button.text == "Играть":
                                print("Нажата кнопка 'Играть'")
                                # Здесь можно добавить логику для перехода на окно с выбором режима игры
                            elif button.text == "Настройки":
                                print("Нажата кнопка 'Настройки'")
                                # Здесь можно добавить логику для перехода на окно настроек

            self.screen.fill((0, 0, 255))  # Заливаем экран синим цветом
            for button in self.buttons:
                button.draw(self.screen)

            pygame.display.flip()

pygame.init()
game_window = GameWindow()
game_window.run()
pygame.quit()
sys.exit()
if __name__ == '__main__':
      App().run()
    # Demo().run()