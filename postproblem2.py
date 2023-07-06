import pygame


def _draw_text(surface: pygame.Surface, font: pygame.font.SysFont, text: str) -> None:
    text_image = font.render(text, True, pygame.Color(255, 255, 255))
    surface.blit(text_image, (10, 10))

def test(key):
    if(65 <= key <= 90):
        return True
    if(97 <= key <= 122):
        return True 
    if(48 <= key <= 57):
        return True
    return False


def run() -> None:
    pygame.init()

    try:
        surface = pygame.display.set_mode((600, 600))
        font = pygame.font.SysFont(None, 24)
        clock = pygame.time.Clock()

        running = True
       
        keys_states = dict()
        while running:
            clock.tick(30)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    break
                elif event.type == pygame.KEYDOWN:
                    key = event.key
                    if test(key):
                        keys_states[key] = True
                elif event.type == pygame.KEYUP:
                    key = event.key
                    if test(key):
                        keys_states[key] = False
            validkeys=[]
            for k in keys_states:
                if keys_states[k]:
                    validkeys.append(chr(k))
            validkeys.sort()
            surface.fill(pygame.Color(128, 128, 128))
            _draw_text(surface, font, ''.join(validkeys))

            pygame.display.flip()

    finally:
        pygame.quit()


if __name__ == '__main__':
    run()