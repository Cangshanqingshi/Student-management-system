/*本程序旨在模拟学生选课、老师排课、助教调课的过程。
通过C++，实现了一个课程管理平台，主要功能有：注册、
登录、学生的选课、退课、看已选课程；老师的选课、退
课、查看已选课程加课、调整课程设置、查看教学方式；
以及助教的选课、退课、看已选课程、查看教学方式等功能
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

class Course{
	public:
		int CourseId;	//表示课程编号
		string courseName;	//表示课程名称
		int credit;	//表示课程的学分
		Course(){
		}
		Course(int CourseId, string courseName, int credit);//构造函数
		~Course(){
		}//析构函数
};

	Course c[20];

class Person{
	public:
		string name;	//人名
		int age;		//年龄
		Person(){
		}
		Person(string name, int age);	//构造函数
		~Person(){
		};//析构函数
};

class Teacher : public Person{              //老师
	public:
		int teacherId;	//表示教师id
		int TeachCourse[ ];	//教师所教授的课程的id集合
		int num;
		Teacher(){
			num = 0;
		};
		Teacher(string name, int age, int teacherId, int n);//构造函数,n表示某个教师教授的课程数目
		~Teacher(){
		};//析构函数
		virtual void teach(){
			cout << "i am a teacher, i teach my student" << endl;
		}//讲课的方法
		virtual void setCourseId(){
			cout << "现在您正在修订自己所教授的课程，请按指示操作" <<endl;
			cout << "学校公开设以下课程：" <<endl;
			for(int i = 0; i < 10; i++){
				cout << c[i].courseName << " " <<  c[i].credit << "学分" << " " << c[i].CourseId  <<endl;
			}
			mua : cout << "首先，请输入您所授课程的id:" ;
			int a;
			cin >> a;
			int n;
			for(int i = 0; i < 10; i++){
				if(a == c[i].CourseId ){
					n = a;
				if(a > 1020 || a < 1000){
					cout << "请您输入正确id" <<endl;
					goto mua;
				}
				}
			}
			TeachCourse[num] = c[n].CourseId ;
			num ++;
		}//教师设置自己教授的课程;
		virtual void changCourse(){
			cout << "您可以修改以下课程：" <<endl;
			checkCourse();
			cout << "请输入您要更改的课程id:" <<endl;
			int a;
			cin >> a;
			int n;
			for(int i = 0; i < 10; i++){
				if(a == c[i].CourseId ){
					n = a;
				}
			}
			cout << "您将对" << c[n].courseName << "进行修改" <<endl;
			cout << "您这门课名称改为:" <<endl;
			cin >> c[n].courseName ;
			cout << "您这门课的学分改为:" <<endl;
			cin >> c[n].credit ;
		}//教师调整自己执教的课程
		virtual void deleteCourse(){
			teadelet1 : cout << "您是否退课？（输入操作前的序号）"<<endl;
			cout << "1、是 2、否" <<endl;
			int n;
			cin >> n;
			switch(n){
				case 1:
					teadelet3 : checkCourse();
					cout << "您要退第几门课：";
					int num1;
					cin >> num1;
					for(int i = num1-1; i < 20; i++){
						TeachCourse[i] = TeachCourse[i+1];
					}
					num--;
					break;
				case 2:
					teadelet2 : cout << "接下来您要？" <<endl;
					cout << "1.继续退课 2.退出" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto teadelet3;
							break;
						case 2:
							break;
						default:
							cout << "请您按规则操作！！！" <<endl;
							goto teadelet2;
					}
					break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto teadelet1;
			}
		}
		virtual void checkCourse(){
			cout << "您正执教的课程：" <<endl;
			for(int i = 0; i < num; i++){
				int n;
				for(int j = 0; j < 20; j++){
					if(TeachCourse[i] == c[j].CourseId ){
						n = j;
					}
				}
				cout << "第" << i+1 << "门:" << c[n].courseName << " " << "学分为：" << c[n].credit << " " << "课程编号" << c[n].CourseId <<endl;
			}
		}//教师查看自己执教的课程
		virtual void addCourse(){
			teaadd1 : cout << "您是否已和教务处联系妥当添课事宜？（请输入操作序号）"<<endl;
			cout << "1、是 2、否" <<endl;
			int n1;
			cin >> n1;
			switch(n1){
				case 1:
					{
					string name;
					};
					int credit, id;
					cout << "您所授科目名称为：";
					cin >> name;
					cout << "您所授科目学分为：";
					cin >> credit;
					cout << "您所授科目id为：";
					cin >> id;
					c[10].CourseId  = id;
					c[10].credit = credit;
					c[10].courseName = name;
					break;
				case 2:
					cout << "请您先联系教务处再做操作！！！" <<endl;
					break;
				default :
					cout << "请您按规则操作！！！"<<endl;
					goto teaadd1;
			}
		}//教师加入自己所授课程
};

class Student : public Person{              //学生
	public:
		int number;	//学生学号(id)
		int courseCount; 	//已选课程的数目
		int myCourses[ ];	//存放已选课程的id的数组
		Student(){
			name;
			age;
			number;
			courseCount = 0;
			for(int i= 0; i < 20; i++){
				myCourses[i] = 0;
			}
		};//构造函数,courseCount表示每个学期至少选多少门课
		~Student(){
		};//析构函数
		virtual void selectCourse(){
			cout << "可选课程有:" <<endl;
			for(int i = 0; i < 10; i++){
				cout << c[i].courseName << " " << c[i].credit << "学分" << " " << c[i].CourseId  <<endl;
			}
			stdselect1 : cout << "请输入您想选的课程的id:";
			int ids;
			cin >> ids;
			int n;
			for(int i = 0; i < 20; i++){
				if(ids == c[i].CourseId ){
					n = i;
				}
				if(ids > 1020 || ids < 1000){
					cout << "请您输入正确id" <<endl;
					goto stdselect1;
				}
			}
			cout << "您输入id对应的课程位为：";
			cout << c[n].courseName << endl;
			cout <<"对应学分为：";
			cout << c[n].credit <<endl;
			cout << "是否选则此课？(请输入您的选择序号)" <<endl;
			cout << "1.是 2.否" << endl;
			int n1;
			cin >> n1;
			switch(n1){
				case 1:
					if(Student::judge () == true){
						myCourses[courseCount] = c[n].CourseId;
						courseCount++;
					}
					else{
						cout << "您选的课程已经足够多了，为了保证您可以完成学业，您无法选则更多的课程了！！！" <<endl;
					}
					break;
				case 2:
					stdselect2 : cout << "接下来您要？" <<endl;
					cout << "1.继续选课 2.退出" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto stdselect1;
							break;
						case 2:
							break;
						default:
							cout << "请您按规则操作！！！" <<endl;
							goto stdselect2;
					}
					break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto stdselect1;
			}
		};	//选课，每选一门课，courseCount数目加1.同时把课程id放到myCourses数组里
		virtual void deleteCourse(){
			studelet1 : cout << "您是否要退课？" <<endl;
			cout << "1、是 2、否" <<endl;
			int n;
			cin >> n;
			switch(n){
				case 1:
					studelet3 : checkCourse();
					cout << "您要退第几门课：";
					int num;
					cin >> num;
					for(int i = num-1; i < 20; i++){
						myCourses[i] = myCourses[i+1];
					}
					courseCount--;
					break;
				case 2:
					studelet2 : cout << "接下来您要？" <<endl;
					cout << "1.继续退课 2.退出" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto studelet3;
							break;
						case 2:
							break;
						default:
							cout << "请您按规则操作！！！" <<endl;
							goto studelet2;
					}
					break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto studelet1;
			}
		};			//退课，每退一门课，courseCount数目减1.同时把课程id从myCourses数组里删除
		virtual void checkCourse(){
			cout << "您已选的课程有：" <<endl;
			for(int i = 0; i < courseCount; i++){
				int n;
				for(int j = 0; j < 20; j++){
					if(myCourses[i] == c[j].CourseId ){
						n = j;
					}
				}
				cout << "第" << i+1 << "门:" << c[n].courseName << " " << "学分为：" << c[n].credit << " " << "课程编号" << c[n].CourseId <<endl;
			}
		}       //查看有多少门课、哪些课
		virtual bool judge(){
			if(courseCount > 4){
				return false;
			}
			else
				return true;
		};					//判断学生该学期是否可完成课程，所选课程数目大于5,表示可以完成该学期的学分，否则不可以完成
};

class TeachingAssistant : public Teacher, public Student{   //助教
	public:
		int courseCount;
		int myCourses[];
		TeachingAssistant(){
			courseCount = 0;
			for(int i= 0; i < 20; i++){
				myCourses[i] = 0;
			}
		};//构造函数
		~TeachingAssistant(){
		};//析构函数
		void teach(){
			cout <<"i am a teaching assistant, i help my teacher teach his students"<<endl;
		}//讲课的方法
		void selectCourse(){
			cout << "可选课程有:" <<endl;
			for(int i = 0; i < 10; i++){
				cout << c[i].courseName << " " << c[i].credit << "学分" << " " << c[i].CourseId  <<endl;
			}
			teaaselect1 : cout << "请输入您想选的课程的id:";
			int ids;
			cin >> ids;
			int n;
			for(int i = 0; i < 20; i++){
				if(ids == c[i].CourseId ){
					n = i;
				}
				if(ids > 1020 || ids < 1000){
					cout << "请您输入正确id" <<endl;
					goto teaaselect1;
				}
			}
			cout << "您输入id对应的课程为：";
			cout << c[n].courseName << endl;
			cout <<"对应学分为：";
			cout << c[n].credit <<endl;
			cout << "是否选则此课？(请输入您的选择序号)" <<endl;
			cout << "1.是 2.否" << endl;
			int n1;
			cin >> n1;
			switch(n1){
				case 1:
					courseCount++;
					myCourses[courseCount-1] = c[n].CourseId;
					break;
				case 2:
					teaaselect2 : cout << "接下来您要？" <<endl;
					cout << "1.继续选课 2.退出" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto teaaselect1;
							break;
						case 2:
							break;
						default:
							cout << "请您按规则操作！！！" <<endl;
							goto teaaselect2;
					}
					break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto teaaselect1;
			}
		};		//选择做某老师的课程助教
		void deleteCourse(){
			teaadelet1 : cout << "您是否要退课？" <<endl;
			cout << "1、是 2、否" <<endl;
			int n;
			cin >> n;
			switch(n){
				case 1:
					teaadelet3 : checkCourse();
					cout << "您要退第几门课：";
					int num1;
					cin >> num1;
					for(int i = num1-1; i < 20; i++){
						myCourses[i] = myCourses[i+1];
					}
					courseCount--;
					break;
				case 2:
					teaadelet2 : cout << "接下来您要？" <<endl;
					cout << "1.继续退课 2.退出" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto teaadelet3;
							break;
						case 2:
							break;
						default:
							cout << "请您按规则操作！！！" <<endl;
							goto teaadelet2;
					}
					break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto teaadelet1;
			}
		};		//退出某老师的课程助教
		void checkCourse(){
			cout << "您已选的课程有：" <<endl;
			for(int i = 0; i < courseCount; i++){
				int n;
				for(int j = 0; j < 20; j++){
					if(myCourses[i] == c[j].CourseId ){
						n = j;
					}
				}
				cout << "第" << i+1 << "门:" << c[n].courseName << " " << "学分为：" << c[n].credit << " " << "课程编号" << c[n].CourseId <<endl;
			}
		}//查看自己已选课程
};

class User{                        //储存用户信息,并执行登录、注册等操作
 public:
 	string name[1000];
	string id[1000];
	int pass[1000];
	int age[1000];
	int num;
	User(){
		num = -1;
		for(int i = 0; i < 1000; i++){
			name[i] = "\0";
			id[i] = "\0";
			pass[i] = 0;
		}
	};
	~User(){
	};
	void AddUser(){
		num++;
		step1 : cout << "请选择你的身份:" ;
		cout << "1.学生 2.老师 3.助教" <<endl;
		string idclassification;
		cin >> idclassification;
		cout << "请输入你的id(学生id第一位为1，老师为2，助教为3):";
		cin >> id[num];
		string idclassification2;
		idclassification2 = id[num].substr(0, 1);
		if(idclassification != idclassification2){
			cout << "请您按照规则建立账户，谢谢!" <<endl;
			goto step1;
		}
		cout << "请输入你的密码:";
		cin >> pass[num];
		cout << "请输入你的年龄以便日后找回密码时的验证" ;
		cin >> age[num];
		cout << "账户已建立成功，您可以登录了！" <<endl;
  	}                                                 //注册
	void login(){
   		cout << "\n正在登录" <<endl;
   		step2 :cout << "\n请选择你的身份:";
		cout << "1.学生 2.老师 3.助教" <<endl;
   		string idclassification;
		cin >> idclassification;
		cout << "请输入你的id:";
		string ids, names;
		int passs;
		cin >> ids;
		int n = -1;
		for(int i = 0; i < 1000; i++){
			if(ids == id[i]){
				n = i;
				break;
			}
		}
		cout << "请输入你的密码:";
		cin >> passs;
		if(pass[n] == passs && n >= 0){
			cout << "\n登录成功！" <<endl;
		}
		else{
			cout << "\nid、密码至少一个有误，请重新输入！！！" <<endl;
			goto step2;
		}
	}                                       //登录
};

int main(){
	c[0].CourseId = 1001;
	c[0].courseName = "数学";
	c[0].credit = 2;
	c[1].CourseId = 1002;
	c[1].courseName = "语文";
	c[1].credit = 2;
	c[2].CourseId = 1003;
	c[2].courseName = "英语";
	c[2].credit = 2;
	c[3].CourseId = 1004;
	c[3].courseName = "物理";
	c[3].credit = 2;
	c[4].CourseId = 1005;
	c[4].courseName = "生物";
	c[4].credit = 2;
	c[5].CourseId = 1006;
	c[5].courseName = "化学";
	c[5].credit = 2;
	c[6].CourseId = 1007;
	c[6].courseName = "政治";
	c[6].credit = 2;
	c[7].CourseId = 1008;
	c[7].courseName = "历史";
	c[7].credit = 2;
	c[8].CourseId = 1009;
	c[8].courseName = "地理";
	c[8].credit = 2;
	c[9].CourseId = 1010;
	c[9].courseName = "体育";
	c[9].credit = 2;
	User user;
	int first;
	Student student1;
	Teacher teacher1;
	TeachingAssistant assistant1;
	laststep : cout << "欢迎使用本系统，请输入您要进行的操作序号" <<endl;
	cout << "1.登录\n2.注册\n" <<endl;
	cin >> first;
	switch(first){
		case 2:
			user.AddUser();
		case 1:
			user.login();
			break;
    	default:
    		cout << "请输入您要进行的操作序号，请勿输入其他内容!!!" <<endl;
    		goto laststep;
	}
	cout << "\n下面进入平台进行操作" <<endl;
	cout << "请选择你的身份:1.学生 2.老师 3.助教" <<endl;
   		int idclassification;
		cin >> idclassification;
 lucky : switch(idclassification){
		case 1:
			cout << "接下来进入选课相关操作" <<endl;
			flag1 : cout << "请输入要进行的操作的序号" <<endl;
			cout << "1、选课 2、退课 3、查看已选课程" <<endl;
			int stu1;
			cin >>stu1;
			switch(stu1){
				case 1:
					student1.selectCourse() ;
					break;
				case 2:
					student1.deleteCourse() ;
					break;
				case 3:
					student1.checkCourse() ;
					break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto flag1;
			}
			break;
		case 2:
			cout << "接下来进行课程调整" <<endl;
			flag2 : cout << "请输入要进行的操作的序号" <<endl;
			cout << "1、选课 2、退课 3、查看已选课程 4、加课 5、调整课程设置 6、查看教学方式" <<endl;
			int tea1;
			cin >>tea1;
			switch(tea1){
				case 1:
					teacher1.setCourseId() ;
					break;
				case 2:
					teacher1.deleteCourse() ;
					break;
				case 3:
					teacher1.checkCourse() ;
					break;
                case 4:
                	teacher1.addCourse() ;
                	break;
				case 5:
					teacher1.changCourse() ;
					break;
                case 6:
                	teacher1.teach() ;
                	break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto flag2;
			}
			break;
		case 3:
			cout << "接下来进行课程调整" <<endl;
			flag3 : cout << "请输入要进行的操作的序号" <<endl;
			cout << "1、选课 2、退课 3、查看已选课程 4、查看教学方式" <<endl;
			int teaa1;
			cin >>teaa1;
			switch(teaa1){
				case 1:
					assistant1.selectCourse() ;
					break;
				case 2:
					assistant1.deleteCourse() ;
					break;
				case 3:
					assistant1.checkCourse() ;
					break;
                case 4:
                	assistant1.teach();
                	break;
				default :
					cout << "请您按规则操作！！！" <<endl;
					goto flag3;
			}
			break;
		default :
			cout << "请按规则操作，谢谢！" <<endl;
			break;
	}
	flag4 : cout << "您要退出、登录其他账号还是进行其他操作？（请输入操作序号）" <<endl;
	cout << "1、退出 2、登录其他账号 3、进行其他操作" <<endl;
	int num10;
	cin >> num10;
	switch(num10){
		case 1:
			return 0;
		case 2:
			goto laststep;
        case 3:
        	goto lucky;
		default :
			cout << "请按规则操作，谢谢！" <<endl;
			goto flag4;
	}
	return 0;
}
