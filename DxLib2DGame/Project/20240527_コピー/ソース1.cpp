#include "DxLib.h"
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void displayStatus(int strikes, int balls, int outs, int hits) {
    char buffer[256];
    sprintf(buffer, "�X�g���C�N: %d  �{�[��: %d  �A�E�g: %d  �q�b�g: %d", strikes, balls, outs, hits);
    DrawString(10, 50, buffer, GetColor(255, 255, 255));
}
int main() {
    // DX���C�u�����̏�����
    if (DxLib_Init() == -1) {
        return -1; // �G���[�����������ꍇ�͏I��
    }
    srand(time(0)); // �����̃V�[�h��ݒ�
    int strikes = 0;
    int balls = 0;
    int outs = 0;
    int hits = 0;
    int pitcherChoice = -1;
    do {
        // ��ʃN���A
        ClearDrawScreen();
        // ��ʂɃ��b�Z�[�W��\��
        DrawString(10, 10, "������I��ł������� (0: �X�g���[�g, 1: �J�[�u, 2: �X���C�_�[, 3: �V���J�[):", GetColor(255, 255, 255));
        displayStatus(strikes, balls, outs, hits);
        // �L�[���͂��󂯕t����
        if (CheckHitKey(KEY_INPUT_0)) pitcherChoice = 0;
        if (CheckHitKey(KEY_INPUT_1)) pitcherChoice = 1;
        if (CheckHitKey(KEY_INPUT_2)) pitcherChoice = 2;
        if (CheckHitKey(KEY_INPUT_3)) pitcherChoice = 3;
        if (pitcherChoice != -1) {
            int batterChoice = rand() % 4;
            char result[256];
            sprintf(result, "�o�b�^�[�̑I��: %d", batterChoice);
            DrawString(10, 70, result, GetColor(255, 255, 255));
            if (pitcherChoice == batterChoice) {
                int hitOutcome = rand() % 100;
                if (hitOutcome < 75) {
                    hits++;
                    DrawString(10, 90, "�q�b�g�I", GetColor(255, 0, 0));
                    strikes = 0;
                    balls = 0;
                }
                else {
                    outs++;
                    DrawString(10, 90, "�A�E�g�I", GetColor(0, 255, 0));
                    strikes = 0;
                    balls = 0;
                }
            }
            else {
                int strikeOutcome = rand() % 100;
                if (strikeOutcome < 75) {
                    strikes++;
                    DrawString(10, 90, "�X�g���C�N�I", GetColor(0, 255, 255));
                    if (strikes == 3) {
                        outs++;
                        DrawString(10, 110, "�O�U�I�A�E�g�I", GetColor(0, 255, 0));
                        strikes = 0;
                        balls = 0;
                    }
                }
                else {
                    balls++;
                    DrawString(10, 90, "�{�[���I", GetColor(255, 255, 0));
                    if (balls == 4) {
                        hits++;
                        DrawString(10, 110, "�t�H�A�{�[���I�q�b�g�I", GetColor(255, 0, 0));
                        strikes = 0;
                        balls = 0;
                    }
                }
            }
            // �����I�����Z�b�g
            pitcherChoice = -1;
        }
        // ��ʂ��X�V
        ScreenFlip();
        // �G�X�P�[�v�L�[�ŏI��
        if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            break;
        }
    } while (outs < 3 && hits < 4);
    ClearDrawScreen();
    if (outs == 3) {
        DrawString(10, 10, "�����I����`�[����}���܂����I", GetColor(255, 255, 255));
    }
    else {
        DrawString(10, 10, "�s�k�I�q�b�g��4��o�܂����B", GetColor(255, 255, 255));
    }
    ScreenFlip();
    WaitKey();
    // DX���C�u�����̏I������
    DxLib_End();
    return 0;
}