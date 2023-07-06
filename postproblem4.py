import math
import pygame


class Blip:
    def __init__(self):
        self._radius = 0
        self._angle = 0


    def move(self) -> None:
        self._radius += 0.001
        self._angle += 1


    def radius(self) -> float:
        return self._radius


    def angle(self) -> float:
        return self._angle


def _determine_blip_center(surface: pygame.Surface, blip: Blip) -> tuple[float, float]:
    rad = blip.radius()
    angl= blip.angle()
    x = rad*math.cos(angl)
    y=rad*math.sin(angl)
    x = surface.get_width() / 2 + rad* surface.get_width() / 2 * math.cos(math.radians(angl * -1))
    y = surface.get_height() / 2 + rad * surface.get_height() / 2 * math.sin(math.radians(angl * -1))
    return (x,y)


def run() -> None:
    pygame.init()

    try:
        surface = pygame.display.set_mode((700, 700), pygame.RESIZABLE)
        
        running = True
        clock = pygame.time.Clock()

        blips = []
        next_blip = 30

        while running:
            clock.tick(30)

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    break
                elif event.type == pygame.VIDEORESIZE:
                    surface = pygame.display.set_mode(event.size, pygame.RESIZABLE)

            for blip in blips:
                blip.move()

            next_blip -= 1

            if next_blip == 0:
                blips.append(Blip())
                next_blip = 30

            surface.fill(pygame.Color(64, 64, 64))

            for blip in blips:
                pygame.draw.circle(
                    surface, pygame.Color(255, 255, 0),
                    _determine_blip_center(surface, blip), 10)
            
            pygame.display.flip()

    finally:
        pygame.quit()


if __name__ == '__main__':
    run()