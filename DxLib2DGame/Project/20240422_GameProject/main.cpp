#include "DxLib.h"//Dx���C�u�����[���C���N���[�h(�ǂݍ���)

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
    SetGraphMode(800, 600, 32);//��ʂ̑傫��

    //DxLib�̏���������
    if (DxLib_Init() == -1)
    {
     //�G���[���N�����璼���ɏI��
        return -1;
    }
    int stringX1 = 10;
    int stringY1 = 50;
    //�~�̏����ʒu
    int circleX = 150;
    int circleY = 200;
    int stringX = 10;
    int stringY = 15;
    int circleColor = GetColor(0, 0, 255);
    int stringColor = GetColor(255, 255, 255);
    int stringColor2 = GetColor(255, 0, 0);
    int mouseX = 0;
    int mouseY = 0;
    //�Q�[�����[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //�����̑傫���̎w
        SetFontSize(32);
        // ��ʂɕ����\��
        //DrawString(10, 15, "HelloWould", StringColor,"X:%d Y:%d",circleX,circleY);
        DrawFormatString(stringX, stringY, stringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //��ʂɉ~��`�悳����
        DrawCircle(circleX, circleY, 30, circleColor, TRUE);
        //�}�E�X�̍��W���擾
        GetMousePoint(&mouseX, &mouseY);
        //�}�E�X���N���b�N���ꂽ��
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit!", stringColor2);
        }

        if (CheckHitKey(KEY_INPUT_UP))
        {
            if (circleY <= 40)
            {
                circleY += 3;
            }
            else
            {
                circleY -= 3;
            }
        }

        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            if (circleY >= 560)
            {
                circleY -= 3;
            }
            else
            {
                circleY += 3;
            }
        }

        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            if (circleX <= 40)
            {
                circleX += 3;
            }
            else
            {
                circleX -= 3;
            }

        }

        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            if (circleX >= 740)
            {
                circleX -= 3;
            }
            else
            {
                circleX += 3;
            }

        }
  
  

            //�~��X���W�ɓ���������
            /*circleX += 40;
            circleY += 30;
            if (circleX >= 800)
            {
                circleX = 0;
                circleY = 0;
            }*/

            //����ʂ̓��e��\��ʂɔ��f������
            ScreenFlip();

    }


    //��ʂɉ~��`�悳����
    DrawCircle(320, 240, 30, GetColor(0, 0, 255), TRUE);

    

    //�L�[���͑҂�
    WaitKey();

    //Dxlib�g�p�̏I������
    DxLib_End();

    //�\�[�X�̏I��
    return 0;
}