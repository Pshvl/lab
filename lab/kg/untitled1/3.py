import pygame
from pygame.locals import *
import sys
from self import self
from button import Button
from dropdown import Dropdown
import ctypes
import os
import uuid
import ctypes
from uuid import uuid4

class Dropdown:
    def __init__(self, items, x, y, width, height):
        self.items = items
        self.rect = pygame.Rect(x, y, width, height)
        self.is_open = False
        self.selected_index = 0
    def update(self):
        # Здесь можно добавить логику обновления состояния выпадающего списка
        pass
    def draw(self, screen, font):
        pygame.draw.rect(screen, (255, 255, 255), self.rect)

        if self.is_open:
            for i, item in enumerate(self.items):
                item_rect = pygame.Rect(self.rect.x, self.rect.y + i * self.rect.height, self.rect.width,
                                        self.rect.height)
                pygame.draw.rect(screen, (200, 200, 200), item_rect)
                item_text = font.render(item, True, (0, 0, 0))
                screen.blit(item_text, (item_rect.x + 10, item_rect.y + 10))

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            if self.rect.collidepoint(event.pos):
                self.is_open = not self.is_open
            elif self.is_open:
                for i in range(len(self.items)):
                    item_rect = pygame.Rect(self.rect.x, self.rect.y + i * self.rect.height, self.rect.width,
                                            self.rect.height)
                    if item_rect.collidepoint(event.pos):
                        self.selected_index = i
                        self.is_open = False

    def get_selected_item(self):
        return self.items[self.selected_index]


class Button:
    """create a button object."""

    def __init__(self, text, pos):
        self.text = text
        self.pos = pos
        self.font = pygame.font.Font(None, 36)
        self.image = self.font.render(self.text, True, (255, 255, 255))
        # self.rect = self.image.get_rect(center=pos)
        self.rect = self.image.get_rect(midtop=pos)

    def draw(self, screen):
        screen.blit(self.image, self.rect)

    def is_clicked(self, pos):
        return self.rect.collidepoint(pos)


class SettingsWindow:
    """Create a settings window."""

    def __init__(self, game_window, songs):
        self.screen = pygame.display.set_mode((800, 600))
        self.screen.fill((250, 120, 144))  # Задаем цвет заполнения окна (R, G, B)
        pygame.display.set_caption("Настройки")
        self.game_window = game_window
        # self.window = pygame.display.set_mode((800, 600))
        self.button = pygame.Rect(50, 50, 200, 50)  # Прямоугольник кнопки
        self.button_color = (255, 0, 0)  # Цвет кнопки
        self.songs = ["Song 1", "Song 2", "Song 3"]
        self.dropdown = Dropdown(self.songs, 50, 120, 200, 50)
        self.selected_song = None
        self.font = pygame.font.Font(None, 36)
        pause_button = Button("Pause", (300, 50))
        next_button = Button("Next Track", (450, 50))
    # def run(self):
    #          running = True
    #
    #          pause_button = Button("Pause", (300, 50))
    #          next_button = Button("Next Track", (450, 50))
    #
    #          while running:
    #              self.screen.fill((250, 120, 144))  # Задаем цвет заполнения окна (R, G, B)
    #
    #              for event in pygame.event.get():
    #                  if event.type == pygame.QUIT:
    #                       running = False
    #                  elif event.type == pygame.MOUSEBUTTONDOWN:
    #                       if pause_button.is_clicked(event.pos):
    #                           if pygame.mixer.music.get_busy():
    #                              pygame.mixer.music.pause()
    #                           else:
    #                               pygame.mixer.music.unpause()
    #                       elif next_button.is_clicked(event.pos):
    #                           # selected_song = self.dropdown.get_selected_item()
    #                           # if selected_song == "Song 1":
    #                           #      self.dropdown.select_item("Song 2")
    #                           # elif selected_song == "Song 2":
    #                           #      self.dropdown.select_item("Song 3")
    #                           # elif selected_song == "Song 3":
    #                           #      self.dropdown.select_item("Song 1")
    #                           #      pygame.mixer.music.load(selected_song.lower() + ".mp3")
    #                           # # pygame.mixer.music.play()
    #                  # selected_song = self.dropdown.get_selected_item()
    #                  # if selected_song == "Song 1":
    #                  #     pygame.mixer.music.load("song1.mp3")
    #                  #     pygame.mixer.music.play()
    #                  # elif selected_song == "Song 2":
    #                  #     pygame.mixer.music.load("song2.mp3")
    #                  #     pygame.mixer.music.play()
    #                  # elif selected_song == "Song 3":
    #                  #     pygame.mixer.music.load("song3.mp3")
    #                  #     pygame.mixer.music.play()
    #
    #
    #
    #                  selected_text = self.font.render("Selected Song: " + selected_song, True, (255, 255, 255))
    #
    #                  self.dropdown.handle_event(event)
    #
    #              self.dropdown.update()
    #              self.dropdown.draw(self.screen,self.font)
    #
    #              # pause_button.draw(self.screen)
    #              # next_button.draw(self.screen)
    #
    #              pygame.display.flip()
    #
    #          pygame.quit()



    def run(self):
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                self.dropdown.handle_event(event)
            selected_song = self.dropdown.get_selected_item()

            if selected_song == "Song 1":
                pygame.mixer.music.load("song1.mp3")
                pygame.mixer.music.play()
            elif selected_song == "Song 2":
                pygame.mixer.music.load("song2.mp3")
                pygame.mixer.music.play()
            elif selected_song == "Song 3":
                pygame.mixer.music.load("song3.mp3")
                pygame.mixer.music.play()
            self.screen.fill((0, 0, 255))
            self.dropdown.draw(self.screen, self.font)
            selected_text = self.font.render("Selected Song: " + selected_song, True, (255, 255, 255))
            self.screen.blit(selected_text, (50, 200))
            pygame.display.flip()


    def close_settings_window(self):
        pygame.quit()
        sys.exit()

    # def return_to_game_window(self):
    #     self.game_window.fullscreen = False
    #     self.game_window.screen = pygame.display.set_mode((800, 600))


class GameWindow:
    """Create a game window."""

    def __init__(self):
        pygame.init()
        self.fullscreen = False
        self.screen = pygame.display.set_mode((800, 600))
        self.clock = pygame.time.Clock()
        self.running = True
        self.screen.fill((250, 120, 144))  # Задаем цвет заполнения окна (R, G, B)
        pygame.display.set_caption("жопа сиськи срать корзинка")
        self.buttons = [Button("Играть", (400, 300)), Button("Настройки", (400, 500))]
        self.songs = ["Song 1", "Song 2", "Song 3"]
        self.settings_window = SettingsWindow(self,
                                              self.songs)  # Передаем список песен при создании объекта SettingsWindow
        self.game_mode_window = GameModeWindow()
    def toggle_fullscreen(self):
        self.fullscreen = not self.fullscreen
        if self.fullscreen:
           self.screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
        else:
           self.screen = pygame.display.set_mode((800, 600))


    def open_settings_window(self):
        settings_window = SettingsWindow(GameWindow, self.songs)
        settings_window.run()
        pygame.display.set_mode((800, 600))  # Подтверждение, что окно вернулось к размеру 800x600
        pygame.display.flip()  # Обновляем экран

    def handle_button_click(self, button):
        if button.text == "Играть":
            print("Нажата кнопка 'Играть'")
            self.game_mode_window.run()
            # Add logic to start the game here
        elif button.text == "Настройки":
            print("Нажата кнопка 'Настройки'")
            self.open_settings_window()
            # Add logic to open settings here


    def run(self):
        running = True
        while running:
            self.screen.fill((250, 120, 144))  # Задаем цвет заполнения окна (R, G, B)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    mouse_pos = pygame.mouse.get_pos()
                    for button in self.buttons:
                        if button.is_clicked(mouse_pos):
                            self.handle_button_click(button)

            # self.screen.fill((0, 0, 255))
            for button in self.buttons:
                button.draw(self.screen)

            pygame.display.flip()


class GameModeWindow:
    def __init__(self):
        # self.game_window = game_window
        self.screen = pygame.display.set_mode((800, 600))
        self.font = pygame.font.SysFont(None, 50)
        self.game_mode = None
        self.fields = [(3, 3), (4, 4), (5, 5)]
        self.selected_field = (3, 3)
        self.running = True
        self.start_button_clicked = False
        self.clock = pygame.time.Clock()
        self.tick_image = pygame.image.load('1.png')  # изображение галочки
        self.cross_image = pygame.image.load('1.png')  # изображение крестика
        self.mode_1v1_rect = pygame.Rect(100, 200, 20, 20)
        self.mode_comp_rect = pygame.Rect(100, 250, 20, 20)

    def draw(self):

        self.screen.fill((250, 120, 144))
        title_text = self.font.render("Выберите режим и поле", True, (0, 0, 0))
        self.screen.blit(title_text, (200, 100))


        # Отрисовка радиокнопок для выбора режима игры
        mode_1v1_button = RadioButton(self.screen, 100, 200, "1 на 1", self.font)
        mode_comp_button = RadioButton(self.screen, 100, 250, "С компьютером", self.font)

        mode_1v1_rect = pygame.draw.rect(self.screen, (255, 255, 255), (100, 200, 20, 20))
        mode_comp_rect = pygame.draw.rect(self.screen, (255, 255, 255), (100, 250, 20, 20))
        pygame.draw.rect(self.screen, (0, 0, 0),  mode_1v1_button, 2)
        pygame.draw.rect(self.screen, (0, 0, 0), mode_comp_button, 2)
        mode_1v1_text = self.font.render("1 на 1", True, (0, 0, 0))
        mode_comp_text = self.font.render("С компьютером", True, (0, 0, 0))
        self.screen.blit(mode_1v1_text, (130, 195))
        self.screen.blit(mode_comp_text, (130, 245))
        # Добавьте сохранение ссылок на созданные объекты RadioButton при необходимости
        self.mode_1v1_button = mode_1v1_button
        self.mode_comp_button = mode_comp_button
        # Отрисовка выпадающего списка для выбора размера поля
        field_text = self.font.render("Выберите размер поля:", True, (0, 0, 0))
        self.screen.blit(field_text, (100, 300))
        for idx, field in enumerate(self.fields):
            field_text = self.font.render(f"{field[0]}x{field[1]}", True, (0, 0, 0))
            field_rect = self.screen.blit(field_text, (100, 350 + idx * 50))
            if field == self.selected_field:
                pygame.draw.rect(self.screen, (0, 0, 255), field_rect, 2)

        start_button = pygame.draw.rect(self.screen, (0, 0, 255), (300, 450, 200, 50))
        start_text = self.font.render("Старт", True, (255, 255, 255))
        self.screen.blit(start_text, (355, 460))
        pygame.display.flip()

    # def handle_events(self, start_button=None):
    #     for event in pygame.event.get():
    #         if event.type == pygame.QUIT:
    #             pygame.quit()
    #             sys.exit()
    #         elif event.type == pygame.MOUSEBUTTONDOWN:
    #             mouse_pos = pygame.mouse.get_pos()
    #             for idx, field in enumerate(self.fields):
    #                 field_rect = pygame.Rect(100, 350 + idx * 50, 100, 50)
    #                 if field_rect.collidepoint(mouse_pos):
    #                     self.selected_field = field
    #             if start_button.collidepoint(mouse_pos):
    #                 self.running = False  # temporary, add logic for starting the game with selected settings
    #                 return

    def process_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos = pygame.mouse.get_pos()
                for idx, field in enumerate(self.fields):
                    field_rect = pygame.Rect(100, 350 + idx * 50, 100, 50)
                    if field_rect.collidepoint(mouse_pos):
                        self.selected_field = field
                if not self.start_button_clicked:  # Проверка, что кнопка "Старт" еще не была нажата
                    if 400 <= mouse_pos[0] <= 500 and 500 <= mouse_pos[1] <= 550:
                        self.start_button_clicked = True
                     # Добавляем обработку событий для радиокнопок
                self.mode_1v1_button.handle_event(event)
                self.mode_comp_button.handle_event(event)
        # Отрисовка радиокнопок
        self.mode_1v1_button.draw()
        self.mode_comp_button.draw()
        return self.running


    def start_game(self):
        if self.selected_field and self.start_button_clicked:
            self.game_mode = "Some Game Mode"  # Здесь можно указать выбранный режим игры
            print(f"Starting the game with mode: {self.game_mode} and field: {self.selected_field}")
            self.running = False  # Останавливаем окно выбора режима

    def run(self):
        while self.running:
            self.draw()
            self.process_events()
            self.start_game()
            self.clock.tick(30)

    # def run(self):
    #     self.running = True
    #     while self.running:
    #         self.draw()
    #         # self.handle_events()
    #         self.running = self.process_events()

class Button2:
    def init2(self, text, pos):
        self.text = text
        self.pos = pos
        self.font = pygame.font.SysFont(None, 50)

    def draw2(self, screen):
        text_render = self.font.render(self.text, True, (0, 0, 0))
        text_rect = text_render.get_rect(center=self.pos)
        screen.blit(text_render, text_rect)

    def is_clicked2(self, pos):
        text_render = self.font.render(self.text, True, (0, 0, 0))
        text_rect = text_render.get_rect(center=self.pos)
        return text_rect.collidepoint(pos)

class RadioButton:
    def __init__(self, screen, x, y, text, font):
        self.screen = screen
        self.x = x
        self.y = y
        self.text = text
        self.font = font
        self.selected = False
        self.rect = pygame.Rect(x, y, 20, 20)

    def draw(self):
        pygame.draw.rect(self.screen, (255, 255, 255), self.rect)
        pygame.draw.rect(self.screen, (0, 0, 0), self.rect, 2)
        text_surface = self.font.render(self.text, True, (0, 0, 0))
        self.screen.blit(text_surface, (self.x + 30, self.y))

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            mouse_pos = pygame.mouse.get_pos()
            if self.rect.collidepoint(mouse_pos):
                self.selected = True
            else:
                self.selected = False

# Далее в вашем коде создайте объекты RadioButton для каждой радиокнопки
icon_file = "1.png"
app_id = str(os.getpid())  # Получаем идентификатор текущего процесса
print(app_id)
appid2 = str(uuid4()) # Генерация уникального GUID
# Загружаем значок из файла
hIcon = ctypes.windll.user32.LoadImageW(None, icon_file,
                                        ctypes.c_uint(0x80000000),
                                        ctypes.c_int(0),
                                        ctypes.c_int(0),
                                        ctypes.c_uint(0x0003))

if hIcon:
    ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID(appid2)
    ctypes.windll.kernel32.SetConsoleIcon(hIcon)
    # Принудительное обновление ярлыка
    SHCNEASSOCCHANGED = 0x08000000
    SHCNFIDLIST = 0x0
    ctypes.windll.shell32.SHChangeNotify(SHCNEASSOCCHANGED, SHCNFIDLIST, 0, 0)

icon = pygame.image.load('1.png')  # замените 'path_to_your_icon.ico' на путь к вашей иконке
pygame.display.set_icon(icon)
pygame.init()


game_window = GameWindow()
# game_window = GameModeWindow()
game_window.run()
pygame.quit()
sys.exit()
