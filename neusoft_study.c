/*
	注意：
		1.文件默认位置 C:\\zuoye.txt
		2.选择y/n部分需要升级---->完成选择y确定，n取消，其他字符提示重新输入
		3.学号不能重复，判断重复部分已经注释在 repeat 函数，存在1个error，需要修改 
*/


#include"neusoft_study.h";

// 输入部分，输入学生初始化信息
void input_stu(){
	int i;
	// 声明调用 write_file 函数
	void write_file();
	//int repeat();
	
	for(i=0;;i++){
		printf("请输入学生的学号:\n");
		scanf("%s",stus[i].number);
		getchar();
		/*
		if(repeat(i)==0){
			printf("学号重复无法添加");
			break;
		}
		*/
		printf("请输入学生的姓名:\n");
		scanf("%s",stus[i].name);
		getchar();
		printf("请输入学生的性别:\n");
		scanf("%c",&stus[i].sex);
		printf("请输入学生的语文成绩:\n");
		scanf("%f",&stus[i].scores.chinese);
		printf("请输入学生的数学:\n");
		scanf("%f",&stus[i].scores.math);
		printf("请输入学生的C语言成绩:\n");
		scanf("%f",&stus[i].scores.c_language);
		printf("\n");
		// 计算总分和平均分
		stus[i].js_scores.sum_scores=stus[i].scores.chinese+stus[i].scores.math+stus[i].scores.c_language;
		stus[i].js_scores.average=stus[i].js_scores.sum_scores/3;
		stus_sum++;
		printf("是否继续输入学生数据？请选择(y/n)\n");
		getchar();
		if(getchar()=='y'){
			continue;
		}else{
			break;
		}
	}
	write_file();
}

// 删除一个学生数据
void delete_stu(){
	char delete_choose[10];
	int i;

	while(1){
		// 判断是否可以进行删除操作
		if(stus_sum==0){
			printf("没有任何数据，无法进行删除操作！\n");
			break;
		}

		printf("请输入需要删除的学生的学号\n");
		scanf("%s",delete_choose);
		getchar();
		
		// 删除判断部分以及删除后构造新数据部分
		for(i=0;i<stus_sum;i++){
			if(strcmp(delete_choose,stus[i].number)==0){
				// 打印需要删除的学生的信息并且判断
				printf("\n");
				printf("--------------------------------------------------------------------------------");
				printf("学号	姓名    性别   语文成绩  数学成绩  C语言成绩    总分    平均分\n");
				printf("%-8s%-9s%-6c%-10.1f%-10.1f%-13.1f%-8.1f%-10.1f\n",stus[i].number,stus[i].name,stus[i].sex,stus[i].scores.chinese,stus[i].scores.math,stus[i].scores.c_language,stus[i].js_scores.sum_scores,stus[i].js_scores.average);
				printf("--------------------------------------------------------------------------------");
				printf("\n");
				printf("确定要删除这个学生么？(y/n)\n");
				if(getchar()=='y'){
					// 删除部分
					for(;i<stus_sum-1;i++){
						stus[i]=stus[i+1];
					}
					stus_sum--;
				}
				break;
			}
			if(i==stus_sum-1){
				printf("没有找到该学号的学生\n");
				break;
			}
		}

		printf("是否继续进行删除操作？请选择(y/n)\n");
		getchar();
		if(getchar()=='n'){
			break;
		}
	}
	write_file();
}

// 修改一个学生数据
void alter_stu(){
	int choose;
	char alter_choose[10];
	int i;
	// 声明函数
	void alter_menu();
	//int repeat();

	while(1){
		// 判断是否可以进行修改操作
		if(stus_sum==0){
			printf("没有任何数据，无法进行修改操作！\n");
			break;
		}

		// 运行修改控制台
		alter_menu();

		// switch选择部分
		while(1){
			printf("请输入需要完成的操作前的序号\n");
			scanf("%d",&choose);
			switch(choose){
				case 0: return;
				case 1: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新学号:\n");
									scanf("%s",stus[i].number);
									getchar();
									/*
									if(repeat(i)==0){
										printf("学号重复无法添加！");
										break;
									}
									*/
									printf("请输入学生的新姓名:\n");
									scanf("%s",stus[i].name);
									getchar();
									printf("请输入学生的新性别:\n");
									scanf("%c",&stus[i].sex);
									printf("请输入学生的新语文成绩:\n");
									scanf("%f",&stus[i].scores.chinese);
									printf("请输入学生的新数学:\n");
									scanf("%f",&stus[i].scores.math);
									printf("请输入学生的新C语言成绩:\n");
									scanf("%f",&stus[i].scores.c_language);
									printf("\n");
									// 计算新的总分与平均分
									stus[i].js_scores.sum_scores=stus[i].scores.chinese+stus[i].scores.math+stus[i].scores.c_language;
									stus[i].js_scores.average=stus[i].js_scores.sum_scores/3;
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				case 2: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新学号:\n");
									scanf("%s",stus[i].number);
									getchar();
									/*
									if(repeat(i)==1){
										printf("学号重复无法添加！");
										break;
									}
									*/
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				case 3: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							getchar();
	
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新姓名:\n");
									scanf("%s",stus[i].name);
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				case 4: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							getchar();
	
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新性别:\n");
									scanf("%c",&stus[i].sex);
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				case 5: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							getchar();
	
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新语文成绩:\n");
									scanf("%f",&stus[i].scores.chinese);
									// 计算新的总分与平均分
									stus[i].js_scores.sum_scores=stus[i].scores.chinese+stus[i].scores.math+stus[i].scores.c_language;
									stus[i].js_scores.average=stus[i].js_scores.sum_scores/3;
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				case 6: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							getchar();
	
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新数学:\n");
									scanf("%f",&stus[i].scores.math);
									// 计算新的总分与平均分
									stus[i].js_scores.sum_scores=stus[i].scores.chinese+stus[i].scores.math+stus[i].scores.c_language;
									stus[i].js_scores.average=stus[i].js_scores.sum_scores/3;
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				case 7: {
							printf("请输入需要修改的学生的学号\n");
							scanf("%s",alter_choose);
							getchar();
	
							for(i=0;i<stus_sum;i++){
								if(strcmp(alter_choose,stus[i].number)==0){
									printf("请输入学生的新C语言成绩:\n");
									scanf("%f",&stus[i].scores.c_language);
									// 计算新的总分与平均分
									stus[i].js_scores.sum_scores=stus[i].scores.chinese+stus[i].scores.math+stus[i].scores.c_language;
									stus[i].js_scores.average=stus[i].js_scores.sum_scores/3;
									break;
								}
								if(i==stus_sum-1){
									printf("没有找到该学号的学生\n");
									break;
								}
							}
						};break;
				default: {
							printf("请输入正确的序号！");
							break;
						 }
			}
			getchar();
			printf("是否继续进行修改操作？请选择(y/n)\n");
			getchar();
			if(getchar()=='n'){
				break;
			}
		}
	}
	write_file();
}

// 根据学号进行查找部分
void find_stu(){
	char find_choose[10];
	int i;

	// 声明 pr_stu() 函数
	void pr_stu();

	while(1){
		// 判断是否可以进行查找操作
		if(stus_sum==0){
			printf("没有任何数据，无法进行查找操作！\n");
			break;
		}

		printf("请输入查找的学生的学号\n");
		scanf("%s",find_choose);
		getchar();
		
		// 匹配部分以及调用显示部分
		for(i=0;i<stus_sum;i++){
			if(strcmp(find_choose,stus[i].number)==0){
				printf("\n");
				printf("\n");
				printf("--------------------------------------------------------------------------------");
				printf("学号	姓名    性别   语文成绩  数学成绩  C语言成绩    总分    平均分\n");
				printf("%-8s%-9s%-6c%-10.1f%-10.1f%-13.1f%-8.1f%-10.1f\n",stus[i].number,stus[i].name,stus[i].sex,stus[i].scores.chinese,stus[i].scores.math,stus[i].scores.c_language,stus[i].js_scores.sum_scores,stus[i].js_scores.average);
				printf("--------------------------------------------------------------------------------");
				printf("\n");
				printf("\n");
				break;
			}
			if(i==stus_sum-1){
				printf("没有找到该学号的学生\n");
				break;
			}
		}
		printf("是否继续进行查找？(y/n)\n");
		if(getchar()=='n'){
			break;
		}
	}
}

// 根据总分进行排序并且输出
void sorting_sumscore(){
	// 排序方式：冒泡排序
	int i,j;
	// 声明函数
	void pr_stu();
	void write_file();
	
	for(i=0;i<stus_sum;i++){
		for(j=i+1;j<stus_sum;j++){
			if(stus[i].js_scores.sum_scores>stus[j].js_scores.sum_scores){
				// 这里是互换，将两组数据完全互相交换
				temp=stus[i];
				stus[i]=stus[j];
				stus[j]=temp;
			}
		}
	}
	pr_stu();
	write_file();
}

// 根据学号进行排序并且输出
void sorting_number(){
	// 排序方式：冒泡排序
	int i,j;
	// 声明函数
	void pr_stu();
	void write_file();
	
	for(i=0;i<stus_sum;i++){
		for(j=i+1;j<stus_sum;j++){
			if(strcmp(stus[i].number,stus[j].number)>0){
				// 这里是互换，将两组数据完全互相交换
				temp=stus[i];
				stus[i]=stus[j];
				stus[j]=temp;
			}
		}
	}
	pr_stu();
	write_file();
}

// 控制台输出函数，输出控制台
void menu(){
	printf("-------------------------------学生成绩管理系统---------------------------------\n");
	printf("\n");
	printf("                   请输入对应的操作数字\n");
	printf("\n");
	printf("                   1.增加学生信息\n");
	printf("                   2.删除学生信息\n");
	printf("                   3.修改学生信息\n");
	printf("                   4.按学号查找学生信息\n");
	printf("                   5.按总成绩顺序排序后显示学生信息\n");
	printf("                   6.按学号顺序排序后显示学生信息\n");
	printf("                   7.显示所有学生信息\n");
	printf("                   8.清理屏幕\n");
	printf("                   0.退出\n");
	printf("--------------------------------------------------------------------------------\n");
}

// 控制台输出函数，修改的多项选择控制台
void alter_menu(){
	printf("-------------------------------修改方法选择系统---------------------------------\n");
	printf("\n");
	printf("                   请输入对应的操作数字\n");
	printf("\n");
	printf("                   0.返回主界面\n");
	printf("                   1.全部修改\n");
	printf("                   2.修改学号\n");
	printf("                   3.修改名字\n");
	printf("                   4.修改性别\n");
	printf("                   5.修改语文成绩\n");
	printf("                   6.修改数学成绩\n");
	printf("                   7.修改C语言成绩\n");
	printf("--------------------------------------------------------------------------------\n");
}

// 显示部分，显示所有

void pr_stu(){
	int i;
	
	printf("\n");
	printf("\n");
	printf("--------------------------------------------------------------------------------");
	printf("学号	姓名    性别   语文成绩  数学成绩  C语言成绩    总分    平均分\n");
	for(i=0;i<stus_sum;i++){
		printf("%-8s%-9s%-6c%-10.1f%-10.1f%-13.1f%-8.1f%-10.1f\n",stus[i].number,stus[i].name,stus[i].sex,stus[i].scores.chinese,stus[i].scores.math,stus[i].scores.c_language,stus[i].js_scores.sum_scores,stus[i].js_scores.average);
	}
	printf("--------------------------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("按任意键继续.......");
	getchar();
	getchar();
}

/*
// 判断学号是否重复
int repeat(int add_i){
	int repeat_i;
	char session[10];

	scanf("%s",session);

	for(repeat_i=0;repeat_i<stus_sum;repeat_i++){
		if(strcmp(stus->number[add_i],stus->number[repeat_i])==0){
			return 1;
		}
		if(repeat_i=stus_sum-1){
			strcpy(stus[add_i].number,session);
			return 2;
		}
	}
}
*/

// 文件操作部分
// 写入文件部分
void write_file(){
	fp=fopen("C:\\zuoye.txt","w");
	fwrite(&stus_sum,sizeof(int),1,fp);
	fwrite(stus,sizeof(struct stu),stus_sum,fp);
	fclose(fp);
}
// 读取文件部分
void read_file(){
	fp=fopen("C:\\zuoye.txt","r");
	if(fp!=NULL){
		fread(&stus_sum,sizeof(int),1,fp);
		fread(stus,sizeof(struct stu),stus_sum,fp);
	}else{
		printf("该文件不存在，需要重新输入学生数据并产生文件\n");
	}
	fclose(fp);
}

// 程序开始页面函数
void begin(){
	printf("\n");
	printf("--------------------------------------------------------------------------------");
	printf("                           欢迎使用学生管理系统！\n");
	printf("                            按任意键进入控制台\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                             哈尔滨师范大学\n");
	printf("\n");
	printf("                        计算机科学与信息工程学院\n");
	printf("--------------------------------------------------------------------------------");
	if(getchar()=='\n'){
		system("cls");
	}
}

// 主函数开始
int main(){
	// 定义参数部分
	int choose=0;

	// 首先读取文件信息，没有则报错
	read_file();

	// 程序开始页面调用
	begin();

	// switch 选择部分
	while(1){
		// 判断是否有数据可以进行操作，没有则进行提示
		if(stus_sum==0){
			printf("                          注意：当前文件内没有任何数据！\n");
			printf("\n");
		}

		// 调出控制台
		menu();
		printf("请输入需要完成的操作前的序号\n");
		scanf("%d",&choose);
		switch(choose){
			case 0: exit(1);
			case 1: input_stu();break;
			case 2: delete_stu();break;
			case 3: alter_stu();break;
			case 4: find_stu();break;
			case 5: sorting_sumscore();break;
			case 6: sorting_number();break;
			case 7: pr_stu();break;
			case 8: system("cls");break;
			default: {
						printf("请输入正确的序号！");
						break;
					 }
		}
	}

	// F5停留dos页
	system("pause");
}
