#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int main(void)
{
	//�ϐ��錾
	int plyScore = 0, emyScore = 0;
	int ply, emy;
	int round = 0;
	int maxRound = 5;
	//�����̏�����
	srand((unsigned int)time(NULL));
	//�Q�[���J�n
	while (round < maxRound || plyScore == emyScore)
	{
		//���E���h�J�E���g�A�b�v
		round++;
		//�v���C���[�^�[��
		printf("PlayerTurn\n");
		emy = rand() % 3;
		printf("%d", emy);
		while (true)
		{
			scanf("%d", &ply);
			if (0 > ply || 3 < ply)
			{
				printf("���͂Ɍ�肪����܂��B�ēx���͂��ĉ������B\n");
			}
			else
			{
				break;
			}
		}
		//����
		if (ply != emy)
		{
			printf("Goal\n");
			plyScore++;
		}
		else
		{
			printf("Stop!\n");
		}
		//CPU�^�[��
		printf("EnemyTurn\n");
		emy = rand() % 3;
		printf("%d", emy);
		while (true)
		{
			scanf("%d", &ply);
			if (0 > ply || 3 < ply)
			{
				printf("���͂Ɍ�肪����܂��B�ēx���͂��ĉ������B\n");
			}
			else
			{
				break;
			}
		}
		//����
		if (ply != emy)
		{
			printf("Goal\n");
			emyScore++;
		}
		else
		{
			printf("Stop!\n");
		}

		printf("%dRound\n PLAYER:%d vs ENEMY:%d\n", round, plyScore, emyScore);
		//�T�h���f�X�˓��I�o
		if (round == maxRound && plyScore == emyScore)
		{
			printf("�T�h���f�X�ɓ˓����܂����B\n");
		}

	}
	//��������
	if (plyScore > emyScore)
	{
		printf("PLAYER WINNER!!\n");
	}
	else
	{
		printf("ENEMY WINNER!!\n");
	}
	return 0;
}