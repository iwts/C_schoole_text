// 调用工程中需要的库
#include<stdio.h>
#include<string.h>

// 结构体部分，每个学生的信息数据

	// 分数结构体
	struct score{
		float chinese;
		float math;
		float c_language;
	};
	// 对分数进行操作的结构体
	struct js_score{
		float average;
		float sum_scores;
	};
	// 其他信息结构体
	struct stu{
		char number[10];
		char name[20];
		char sex;
		struct score scores;
		struct js_score js_scores;
	};

// 声明部分，声明学生数组
struct stu stus[1000];

// 声明一个temp成员，用于排序的时候临时储存其他成员数据
struct stu temp;

// 声明fp，选择文件
FILE *fp;

// 初始化 stus_sum 变量，确定实际上总共的学生数
int stus_sum=0;
