#include "DxLib.h"
#include <math.h>
#include <stdio.h>

//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define STRAT_STRING_X 230
#define STRAT_STRING_Y 520

//�t���[���J�E���g
double frameCount = 0;
//�f���^����
int prevCount, nowCout;
//�摜�n���h���ϐ�
int startScreenImage;
int alpha;
//���C���֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---------------------------//
    // ��{�ݒ�
    //---------------------------//
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);//��ʂ̑傫��

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
        //�G���[���N�����璼���ɏI��
        return -1;
    }
    startScreenImage = LoadGraph("img/tittle01.png");
    int stringColor = GetColor(255, 99,71 );
    //---------------------------//
    // �Q�[�����[�v
    //---------------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        nowCout = GetNowCount();

        double deltaTime = (nowCout - prevCount) / 1000.0;
        //�t���[���J�E���g�ɒǉ�
        frameCount += deltaTime * 1000;

        //�摜�̕`��
        DrawExtendGraph(0, 0, SCREEN_X, SCREEN_Y, startScreenImage, TRUE);
        //�A���t�@�n���v�Z
        alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.003))));

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            SetFontSize(30);
            DrawFormatString(STRAT_STRING_X, STRAT_STRING_Y, stringColor, "�G���^�[�ŃX�^�[�g");

            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            prevCount = nowCout;
    }


    //Dxlib�I������
    DxLib_End();

    return 0;

}