/*������ּ��ģ��ѧ��ѡ�Ρ���ʦ�ſΡ����̵��εĹ��̡�
ͨ��C++��ʵ����һ���γ̹���ƽ̨����Ҫ�����У�ע�ᡢ
��¼��ѧ����ѡ�Ρ��˿Ρ�����ѡ�γ̣���ʦ��ѡ�Ρ���
�Ρ��鿴��ѡ�γ̼ӿΡ������γ����á��鿴��ѧ��ʽ��
�Լ����̵�ѡ�Ρ��˿Ρ�����ѡ�γ̡��鿴��ѧ��ʽ�ȹ���
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

class Course{
	public:
		int CourseId;	//��ʾ�γ̱��
		string courseName;	//��ʾ�γ�����
		int credit;	//��ʾ�γ̵�ѧ��
		Course(){
		}
		Course(int CourseId, string courseName, int credit);//���캯��
		~Course(){
		}//��������
};

	Course c[20];

class Person{
	public:
		string name;	//����
		int age;		//����
		Person(){
		}
		Person(string name, int age);	//���캯��
		~Person(){
		};//��������
};

class Teacher : public Person{              //��ʦ
	public:
		int teacherId;	//��ʾ��ʦid
		int TeachCourse[ ];	//��ʦ�����ڵĿγ̵�id����
		int num;
		Teacher(){
			num = 0;
		};
		Teacher(string name, int age, int teacherId, int n);//���캯��,n��ʾĳ����ʦ���ڵĿγ���Ŀ
		~Teacher(){
		};//��������
		virtual void teach(){
			cout << "i am a teacher, i teach my student" << endl;
		}//���εķ���
		virtual void setCourseId(){
			cout << "�����������޶��Լ������ڵĿγ̣��밴ָʾ����" <<endl;
			cout << "ѧУ���������¿γ̣�" <<endl;
			for(int i = 0; i < 10; i++){
				cout << c[i].courseName << " " <<  c[i].credit << "ѧ��" << " " << c[i].CourseId  <<endl;
			}
			mua : cout << "���ȣ������������ڿγ̵�id:" ;
			int a;
			cin >> a;
			int n;
			for(int i = 0; i < 10; i++){
				if(a == c[i].CourseId ){
					n = a;
				if(a > 1020 || a < 1000){
					cout << "����������ȷid" <<endl;
					goto mua;
				}
				}
			}
			TeachCourse[num] = c[n].CourseId ;
			num ++;
		}//��ʦ�����Լ����ڵĿγ�;
		virtual void changCourse(){
			cout << "�������޸����¿γ̣�" <<endl;
			checkCourse();
			cout << "��������Ҫ���ĵĿγ�id:" <<endl;
			int a;
			cin >> a;
			int n;
			for(int i = 0; i < 10; i++){
				if(a == c[i].CourseId ){
					n = a;
				}
			}
			cout << "������" << c[n].courseName << "�����޸�" <<endl;
			cout << "�����ſ����Ƹ�Ϊ:" <<endl;
			cin >> c[n].courseName ;
			cout << "�����ſε�ѧ�ָ�Ϊ:" <<endl;
			cin >> c[n].credit ;
		}//��ʦ�����Լ�ִ�̵Ŀγ�
		virtual void deleteCourse(){
			teadelet1 : cout << "���Ƿ��˿Σ����������ǰ����ţ�"<<endl;
			cout << "1���� 2����" <<endl;
			int n;
			cin >> n;
			switch(n){
				case 1:
					teadelet3 : checkCourse();
					cout << "��Ҫ�˵ڼ��ſΣ�";
					int num1;
					cin >> num1;
					for(int i = num1-1; i < 20; i++){
						TeachCourse[i] = TeachCourse[i+1];
					}
					num--;
					break;
				case 2:
					teadelet2 : cout << "��������Ҫ��" <<endl;
					cout << "1.�����˿� 2.�˳�" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto teadelet3;
							break;
						case 2:
							break;
						default:
							cout << "�������������������" <<endl;
							goto teadelet2;
					}
					break;
				default :
					cout << "�������������������" <<endl;
					goto teadelet1;
			}
		}
		virtual void checkCourse(){
			cout << "����ִ�̵Ŀγ̣�" <<endl;
			for(int i = 0; i < num; i++){
				int n;
				for(int j = 0; j < 20; j++){
					if(TeachCourse[i] == c[j].CourseId ){
						n = j;
					}
				}
				cout << "��" << i+1 << "��:" << c[n].courseName << " " << "ѧ��Ϊ��" << c[n].credit << " " << "�γ̱��" << c[n].CourseId <<endl;
			}
		}//��ʦ�鿴�Լ�ִ�̵Ŀγ�
		virtual void addCourse(){
			teaadd1 : cout << "���Ƿ��Ѻͽ�����ϵ�׵�������ˣ��������������ţ�"<<endl;
			cout << "1���� 2����" <<endl;
			int n1;
			cin >> n1;
			switch(n1){
				case 1:
					{
					string name;
					};
					int credit, id;
					cout << "�����ڿ�Ŀ����Ϊ��";
					cin >> name;
					cout << "�����ڿ�Ŀѧ��Ϊ��";
					cin >> credit;
					cout << "�����ڿ�ĿidΪ��";
					cin >> id;
					c[10].CourseId  = id;
					c[10].credit = credit;
					c[10].courseName = name;
					break;
				case 2:
					cout << "��������ϵ������������������" <<endl;
					break;
				default :
					cout << "�������������������"<<endl;
					goto teaadd1;
			}
		}//��ʦ�����Լ����ڿγ�
};

class Student : public Person{              //ѧ��
	public:
		int number;	//ѧ��ѧ��(id)
		int courseCount; 	//��ѡ�γ̵���Ŀ
		int myCourses[ ];	//�����ѡ�γ̵�id������
		Student(){
			name;
			age;
			number;
			courseCount = 0;
			for(int i= 0; i < 20; i++){
				myCourses[i] = 0;
			}
		};//���캯��,courseCount��ʾÿ��ѧ������ѡ�����ſ�
		~Student(){
		};//��������
		virtual void selectCourse(){
			cout << "��ѡ�γ���:" <<endl;
			for(int i = 0; i < 10; i++){
				cout << c[i].courseName << " " << c[i].credit << "ѧ��" << " " << c[i].CourseId  <<endl;
			}
			stdselect1 : cout << "����������ѡ�Ŀγ̵�id:";
			int ids;
			cin >> ids;
			int n;
			for(int i = 0; i < 20; i++){
				if(ids == c[i].CourseId ){
					n = i;
				}
				if(ids > 1020 || ids < 1000){
					cout << "����������ȷid" <<endl;
					goto stdselect1;
				}
			}
			cout << "������id��Ӧ�Ŀγ�λΪ��";
			cout << c[n].courseName << endl;
			cout <<"��Ӧѧ��Ϊ��";
			cout << c[n].credit <<endl;
			cout << "�Ƿ�ѡ��˿Σ�(����������ѡ�����)" <<endl;
			cout << "1.�� 2.��" << endl;
			int n1;
			cin >> n1;
			switch(n1){
				case 1:
					if(Student::judge () == true){
						myCourses[courseCount] = c[n].CourseId;
						courseCount++;
					}
					else{
						cout << "��ѡ�Ŀγ��Ѿ��㹻���ˣ�Ϊ�˱�֤���������ѧҵ�����޷�ѡ�����Ŀγ��ˣ�����" <<endl;
					}
					break;
				case 2:
					stdselect2 : cout << "��������Ҫ��" <<endl;
					cout << "1.����ѡ�� 2.�˳�" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto stdselect1;
							break;
						case 2:
							break;
						default:
							cout << "�������������������" <<endl;
							goto stdselect2;
					}
					break;
				default :
					cout << "�������������������" <<endl;
					goto stdselect1;
			}
		};	//ѡ�Σ�ÿѡһ�ſΣ�courseCount��Ŀ��1.ͬʱ�ѿγ�id�ŵ�myCourses������
		virtual void deleteCourse(){
			studelet1 : cout << "���Ƿ�Ҫ�˿Σ�" <<endl;
			cout << "1���� 2����" <<endl;
			int n;
			cin >> n;
			switch(n){
				case 1:
					studelet3 : checkCourse();
					cout << "��Ҫ�˵ڼ��ſΣ�";
					int num;
					cin >> num;
					for(int i = num-1; i < 20; i++){
						myCourses[i] = myCourses[i+1];
					}
					courseCount--;
					break;
				case 2:
					studelet2 : cout << "��������Ҫ��" <<endl;
					cout << "1.�����˿� 2.�˳�" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto studelet3;
							break;
						case 2:
							break;
						default:
							cout << "�������������������" <<endl;
							goto studelet2;
					}
					break;
				default :
					cout << "�������������������" <<endl;
					goto studelet1;
			}
		};			//�˿Σ�ÿ��һ�ſΣ�courseCount��Ŀ��1.ͬʱ�ѿγ�id��myCourses������ɾ��
		virtual void checkCourse(){
			cout << "����ѡ�Ŀγ��У�" <<endl;
			for(int i = 0; i < courseCount; i++){
				int n;
				for(int j = 0; j < 20; j++){
					if(myCourses[i] == c[j].CourseId ){
						n = j;
					}
				}
				cout << "��" << i+1 << "��:" << c[n].courseName << " " << "ѧ��Ϊ��" << c[n].credit << " " << "�γ̱��" << c[n].CourseId <<endl;
			}
		}       //�鿴�ж����ſΡ���Щ��
		virtual bool judge(){
			if(courseCount > 4){
				return false;
			}
			else
				return true;
		};					//�ж�ѧ����ѧ���Ƿ����ɿγ̣���ѡ�γ���Ŀ����5,��ʾ������ɸ�ѧ�ڵ�ѧ�֣����򲻿������
};

class TeachingAssistant : public Teacher, public Student{   //����
	public:
		int courseCount;
		int myCourses[];
		TeachingAssistant(){
			courseCount = 0;
			for(int i= 0; i < 20; i++){
				myCourses[i] = 0;
			}
		};//���캯��
		~TeachingAssistant(){
		};//��������
		void teach(){
			cout <<"i am a teaching assistant, i help my teacher teach his students"<<endl;
		}//���εķ���
		void selectCourse(){
			cout << "��ѡ�γ���:" <<endl;
			for(int i = 0; i < 10; i++){
				cout << c[i].courseName << " " << c[i].credit << "ѧ��" << " " << c[i].CourseId  <<endl;
			}
			teaaselect1 : cout << "����������ѡ�Ŀγ̵�id:";
			int ids;
			cin >> ids;
			int n;
			for(int i = 0; i < 20; i++){
				if(ids == c[i].CourseId ){
					n = i;
				}
				if(ids > 1020 || ids < 1000){
					cout << "����������ȷid" <<endl;
					goto teaaselect1;
				}
			}
			cout << "������id��Ӧ�Ŀγ�Ϊ��";
			cout << c[n].courseName << endl;
			cout <<"��Ӧѧ��Ϊ��";
			cout << c[n].credit <<endl;
			cout << "�Ƿ�ѡ��˿Σ�(����������ѡ�����)" <<endl;
			cout << "1.�� 2.��" << endl;
			int n1;
			cin >> n1;
			switch(n1){
				case 1:
					courseCount++;
					myCourses[courseCount-1] = c[n].CourseId;
					break;
				case 2:
					teaaselect2 : cout << "��������Ҫ��" <<endl;
					cout << "1.����ѡ�� 2.�˳�" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto teaaselect1;
							break;
						case 2:
							break;
						default:
							cout << "�������������������" <<endl;
							goto teaaselect2;
					}
					break;
				default :
					cout << "�������������������" <<endl;
					goto teaaselect1;
			}
		};		//ѡ����ĳ��ʦ�Ŀγ�����
		void deleteCourse(){
			teaadelet1 : cout << "���Ƿ�Ҫ�˿Σ�" <<endl;
			cout << "1���� 2����" <<endl;
			int n;
			cin >> n;
			switch(n){
				case 1:
					teaadelet3 : checkCourse();
					cout << "��Ҫ�˵ڼ��ſΣ�";
					int num1;
					cin >> num1;
					for(int i = num1-1; i < 20; i++){
						myCourses[i] = myCourses[i+1];
					}
					courseCount--;
					break;
				case 2:
					teaadelet2 : cout << "��������Ҫ��" <<endl;
					cout << "1.�����˿� 2.�˳�" <<endl;
					int n2;
					cin >> n2;
					switch(n2){
						case 1:
							goto teaadelet3;
							break;
						case 2:
							break;
						default:
							cout << "�������������������" <<endl;
							goto teaadelet2;
					}
					break;
				default :
					cout << "�������������������" <<endl;
					goto teaadelet1;
			}
		};		//�˳�ĳ��ʦ�Ŀγ�����
		void checkCourse(){
			cout << "����ѡ�Ŀγ��У�" <<endl;
			for(int i = 0; i < courseCount; i++){
				int n;
				for(int j = 0; j < 20; j++){
					if(myCourses[i] == c[j].CourseId ){
						n = j;
					}
				}
				cout << "��" << i+1 << "��:" << c[n].courseName << " " << "ѧ��Ϊ��" << c[n].credit << " " << "�γ̱��" << c[n].CourseId <<endl;
			}
		}//�鿴�Լ���ѡ�γ�
};

class User{                        //�����û���Ϣ,��ִ�е�¼��ע��Ȳ���
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
		step1 : cout << "��ѡ��������:" ;
		cout << "1.ѧ�� 2.��ʦ 3.����" <<endl;
		string idclassification;
		cin >> idclassification;
		cout << "���������id(ѧ��id��һλΪ1����ʦΪ2������Ϊ3):";
		cin >> id[num];
		string idclassification2;
		idclassification2 = id[num].substr(0, 1);
		if(idclassification != idclassification2){
			cout << "�������չ������˻���лл!" <<endl;
			goto step1;
		}
		cout << "�������������:";
		cin >> pass[num];
		cout << "��������������Ա��պ��һ�����ʱ����֤" ;
		cin >> age[num];
		cout << "�˻��ѽ����ɹ��������Ե�¼�ˣ�" <<endl;
  	}                                                 //ע��
	void login(){
   		cout << "\n���ڵ�¼" <<endl;
   		step2 :cout << "\n��ѡ��������:";
		cout << "1.ѧ�� 2.��ʦ 3.����" <<endl;
   		string idclassification;
		cin >> idclassification;
		cout << "���������id:";
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
		cout << "�������������:";
		cin >> passs;
		if(pass[n] == passs && n >= 0){
			cout << "\n��¼�ɹ���" <<endl;
		}
		else{
			cout << "\nid����������һ���������������룡����" <<endl;
			goto step2;
		}
	}                                       //��¼
};

int main(){
	c[0].CourseId = 1001;
	c[0].courseName = "��ѧ";
	c[0].credit = 2;
	c[1].CourseId = 1002;
	c[1].courseName = "����";
	c[1].credit = 2;
	c[2].CourseId = 1003;
	c[2].courseName = "Ӣ��";
	c[2].credit = 2;
	c[3].CourseId = 1004;
	c[3].courseName = "����";
	c[3].credit = 2;
	c[4].CourseId = 1005;
	c[4].courseName = "����";
	c[4].credit = 2;
	c[5].CourseId = 1006;
	c[5].courseName = "��ѧ";
	c[5].credit = 2;
	c[6].CourseId = 1007;
	c[6].courseName = "����";
	c[6].credit = 2;
	c[7].CourseId = 1008;
	c[7].courseName = "��ʷ";
	c[7].credit = 2;
	c[8].CourseId = 1009;
	c[8].courseName = "����";
	c[8].credit = 2;
	c[9].CourseId = 1010;
	c[9].courseName = "����";
	c[9].credit = 2;
	User user;
	int first;
	Student student1;
	Teacher teacher1;
	TeachingAssistant assistant1;
	laststep : cout << "��ӭʹ�ñ�ϵͳ����������Ҫ���еĲ������" <<endl;
	cout << "1.��¼\n2.ע��\n" <<endl;
	cin >> first;
	switch(first){
		case 2:
			user.AddUser();
		case 1:
			user.login();
			break;
    	default:
    		cout << "��������Ҫ���еĲ�����ţ�����������������!!!" <<endl;
    		goto laststep;
	}
	cout << "\n�������ƽ̨���в���" <<endl;
	cout << "��ѡ��������:1.ѧ�� 2.��ʦ 3.����" <<endl;
   		int idclassification;
		cin >> idclassification;
 lucky : switch(idclassification){
		case 1:
			cout << "����������ѡ����ز���" <<endl;
			flag1 : cout << "������Ҫ���еĲ��������" <<endl;
			cout << "1��ѡ�� 2���˿� 3���鿴��ѡ�γ�" <<endl;
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
					cout << "�������������������" <<endl;
					goto flag1;
			}
			break;
		case 2:
			cout << "���������пγ̵���" <<endl;
			flag2 : cout << "������Ҫ���еĲ��������" <<endl;
			cout << "1��ѡ�� 2���˿� 3���鿴��ѡ�γ� 4���ӿ� 5�������γ����� 6���鿴��ѧ��ʽ" <<endl;
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
					cout << "�������������������" <<endl;
					goto flag2;
			}
			break;
		case 3:
			cout << "���������пγ̵���" <<endl;
			flag3 : cout << "������Ҫ���еĲ��������" <<endl;
			cout << "1��ѡ�� 2���˿� 3���鿴��ѡ�γ� 4���鿴��ѧ��ʽ" <<endl;
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
					cout << "�������������������" <<endl;
					goto flag3;
			}
			break;
		default :
			cout << "�밴���������лл��" <<endl;
			break;
	}
	flag4 : cout << "��Ҫ�˳�����¼�����˺Ż��ǽ��������������������������ţ�" <<endl;
	cout << "1���˳� 2����¼�����˺� 3��������������" <<endl;
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
			cout << "�밴���������лл��" <<endl;
			goto flag4;
	}
	return 0;
}
