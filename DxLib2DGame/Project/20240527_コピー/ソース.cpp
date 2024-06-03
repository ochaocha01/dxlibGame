#include"DxLib.h"
#define _USE_MATH_DEFINES
#include<math.h>
#include<stdio.h>
//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200

//�ϊ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    double area;
}circle;
//�Q�[���t���O
bool enterPressedLastFrame = false;  //�G���^�[�L�[�������ꂽ�ǂ����̃t���O
bool gameStartFlag = false;  //�Q�[���J�n�t���O
bool circleGenerationFlag = true;  //�~�̐����t���O
bool gameEndFlag = true;  //�Q�[���I���t���O

//�Q�[���J�E���g
int enterPressCount;
//�\���̂�ϐ��ɂ���
circle Circle;
//�~�̍ő�ʐ�
double circleAreeMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;
//���C���֐�
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//windous�̃��C���œ�����
{
    //------------------------//
    //��{�݌v
    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);
    if (DxLib_Init() == -1)
    {
        return -1;
    }
    //�F�w��
    int CircleColor = GetColor(128, 128, 128);
    //�~�̕`��
    Circle.posX = CIRCLE_POS_X;
    Circle.posY = CIRCLE_POS_Y;
    Circle.radius = CIRCLE_RADIUS_START;

    //------------------------//
    //�Q�[�����[�v
    //------------------------//
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();


        //�G���^�[�L�[�������ăQ�[�����X�^�[�g
        if (CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
        {
            gameStartFlag = !gameStartFlag;
        }
        //�G���^�[�������ꂽ�����L��������
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);
        //�~�̕ω�������
        if (gameStartFlag)
        {
            //�傫������
            if (circleGenerationFlag)
            {
                //���~��5�����₷
                Circle.radius += 5;
            }
        }






        //�~�̕`��
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, CircleColor);
        //����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

    }
    //Dxlib�I������
    DxLib_End();

}
