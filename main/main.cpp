#include <stdio.h>

int da[339][3070] = { 0 };
int main()
{
	FILE *fp1;
	FILE *fp2;
	int i, j;
	fopen_s(&fp1, "H8.csv","r");    // fpָ��ָ���ļ�ͷ��
	fopen_s(&fp2, "1.v", "w");    // fpָ��ָ���ļ�ͷ��
	for (i = 0; i < 339; i++)
	{
		for (j = 0; j < 3070; j++)
		{
			fscanf_s(fp1,"%d",&da[i][j]);
			fseek(fp1, 1L, SEEK_CUR);
			printf("%d", da[i][j]);
		}
		printf("\n");
	}


	for (i = 0; i < 339; i++)
	{
		fprintf(fp2,";\nassign v2c%d = ",i);
		for (j = 0; j < 3070; j++)
		{
			if (da[i][j] != 0)
			{
				fprintf(fp2, "v_c(vn%d,3'O%d) ^ ",j,da[i][j]);//ͬ���printfһ�����Ը�ʽ��ʽ������ı���
			}
		}
	}
	fclose(fp2);//�ر���
	return 0;
}
