

#ifndef _SHELLBALL_PLAYER1_H_
#define _SHELLBALL_PLAYER1_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------


class Player1 : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // anima��o do personagem
    int side;
    int height2;


public:
    int vel;
    Player1();                           // construtor
    ~Player1();                          // destrutor

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    void Reset();
    void Start();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Player1::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif