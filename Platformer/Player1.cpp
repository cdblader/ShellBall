
#include "ShellBall.h"
#include "Ball.h"
#include "Player1.h"

// ---------------------------------------------------------------------------------
void Player1::Reset()
{
    MoveTo(100.0f, window->CenterY(), 0.0f);
    vel = 0;
    side = 2;
}
void Player1::Start()
{
    vel = 300;
}

Player1::Player1()
{
    tileset = new TileSet("Resources/pokeplayer.png", 46, 72, 7, 14);
    anim = new Animation(tileset, 0.12f, true);

    uint SeqUp[3] = { 1,2,3 };
    uint SeqDown[3] = { 4,5,6 };
    uint SeqStill[1] = { 0 };

    height2 = int(60 / 2);
    vel = 0;


    anim->Add(1, SeqDown, 3);
    anim->Add(0, SeqUp, 3);
    anim->Add(2, SeqStill, 1);

    side = 2;


    MoveTo(100.0f, window->CenterY(), 0.0f);

    BBox(new Rect(-17, -height2, 17, height2));

    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player1::~Player1()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Player1::OnCollision(Object* obj)
{
        Ball* ball = (Ball*)obj;

        if (ball->Y() + ball->height2 - 6 < y - height2 && ball->Y() - ball->height2 < y - height2) {
            ball->MoveTo(ball->X(), ball->Y() - 6);
            ball->velY = -ball->velY;
        }
        else if (ball->X() - ball->width2 + 6 > x + 16 && ball->X() + ball->width2 > x + 16) {
            ball->MoveTo(ball->X() + 6, ball->Y());
            ball->velX = -ball->velX;
        }
        else    if (ball->Y() - ball->height2 + 6 > y + height2 && ball->Y() + ball->height2 > y + height2) {
            ball->MoveTo(ball->X(), ball->Y() + 6);
            ball->velY = -ball->velY;
        }
        else     if (ball->X() + ball->width2 - 6 < x - 16 && ball->X() - ball->width2 < x - 16) {
            ball->MoveTo(ball->X() - 6, ball->Y());
            ball->velX = -ball->velX;
        }
        if (ball->velX < 400 && ball->velX > -400) {
            ball->velX = ball->velX * 1.1f;
            ball->velY = ball->velY * 1.1f;
        }

        ball->lastHit = LEFT;
}

// ---------------------------------------------------------------------------------

void Player1::Update()
{


    //Translate(0, -12);

    if (y + height2 > 370)
        MoveTo(x, 370 - height2);

    if (y - height2 < 80)
        MoveTo(x, 80 + height2);


    if (window->KeyDown('Q')) {
        side = 1;
        Translate(0, -vel * gameTime);
    }else    if (window->KeyDown('A')) {
        side = 0;
        Translate(0, vel * gameTime);
    }
    else {
        side = 2;
    }


    anim->Select(side);
    anim->NextFrame();

}

// ---------------------------------------------------------------------------------