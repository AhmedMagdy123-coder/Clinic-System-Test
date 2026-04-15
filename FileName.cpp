<<<<<<< HEAD
#include <iostream>
using namespace std;
int main()
{
	double fare, dis;
	char time,choice ;
	do {
		cout << "enter distance travelled (in km): ";
		cin >> dis;
	
		cout << "enter time for trip (D for day / M for midnight):  ";
		cin >> time;
		if (time == 'D')
		{
			fare = (2 * dis) + 5;
		}
		else if (time == 'M')
		{
			((2 * dis) + 5) + (.1 * ((2 * dis) + 5));

		}
		cout <<"\n" << "total fare is " << fare;

		cout << "do you want to calculator more? ";
		cin >> choice;



	} while (choice == 'y' || choice == 'Y');


	cout << "thank you for using our application have a good day";



	return 0;
=======
#include<iostream>
#include<string>
using namespace std;
// Struct for Doctor
struct doctor
{
    string name;              // اسم الدكتور
    string specialization;// تخصص الدكتور (مثل: قلب، أطفال، جلدية)
    int id;// الرقم التعريفي للدكتور (مثل: 101)
    double ConsultationFee;  // قيمة الكشف بالجنيه
    string AvailableSlots; // المواعيد المتاحة (مثل: Sat-Mon 10AM-2PM)
};// ---------------------- المتغيرات العامة ----------------------
const int Max = 20;   // الحد الأقصى لعدد الدكاترة = 20 (حسب المطلوب)
// ✅ تخزين 3 دكاترة مبدئياً (حسب المتطلبات)
// بنخزنهم مباشرة بعد تعريف الـ array زي ما المطلوب
doctor doctors[Max] = { { "Ahmed Ali", "Cardiology", 101, 500 , "Sat - Mon 10AM - 2PM"},      // Doctor 1
    { "Sali Hassan", "Pediatrics", 102, 400 , "Sun-Wed 12PM-4PM" },    // Doctor 2
    { "Amira Mahmoud", "Dermatology", 103, 450 , "Tue-Thu 9AM-1PM" } };   // Doctor 3
int doctorCount = 3; // عدد الدكاترة الموجودين حالياً (بدأنا بـ 3)
// ---------------------- دالة إضافة دكتور جديد ----------------------
void addDoctor() {
    //الخطوة 1: نتأكد إن في مكان فاضي في الـ array
    if (doctorCount == Max) {
        cout << "Array is full!\n";// الـ array اتسدت خلاص
        return;// نخرج من الدالة من غير ما نكمل
    }
    // الخطوة 2: نعمل متغير مؤقت نخزن فيه بيانات الدكتور الجديد
    doctor d;
    // الخطوة 3: نطلب من المستخدم يدخل البيانات
    cout << "Enter Doctor ID: ";
    cin >> d.id;
    // الخطوة 4: نتأكد إن الـ ID مش موجود قبل كده (مينفعش يتكرر)
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == d.id) {
            cout << "ID already exists!\n";// الـ ID موجود بالفعل
            return;// نخرج من الدالة
        }
    }
    // الخطوة 5: نكمل إدخال باقي البيانات
    cout << "Enter Name: ";
    cin >> d.name;
    cout << "Enter Specialization: ";
    cin >> d.specialization;
    cout << "Enter ConsultationFee: ";
    cin >> d.ConsultationFee;
    cout << "Enter AvailableSlots: ";
    cin >> d.AvailableSlots;
    // الخطوة 6: نخزن الدكتور الجديد في أول مكان فاضي في الـ array
    doctors[doctorCount] = d;
    // الخطوة 7: نزود العداد بـ 1 عشان يعكس إن فيه دكتور جديد
    doctorCount++;
    cout << "Doctor added successfully!\n";//DONE! الحمدلله
}
// ---------------------- دالة حذف دكتور ----------------------
void removeDoctor() {
    int doctorID;
    cout << "Enter Doctor ID to remove: ";
    cin >> doctorID;
    // الخطوة 1: ندور على مكان الدكتور في الـ array
    int doctorIndex = -1; // -1 معناه "لسه ملقتش"
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == doctorID) {
            doctorIndex = i;// لقينا الدكتور في المكان i 
            break;// نخرج من اللوب خلاص
        }
    }  
    // الخطوة 2: لو ملقتش الدكتور، نطبع رسالة ونخرج

    if (doctorIndex == -1) {
        cout << "Doctor not found!\n";
        return;
    }
    // الخطوة 3: نشيل الدكتور عن طريق إزاحة الدكاترة اللي بعده لليسار
    // مثال: عندنا دكاترة في [0,1,2,3] وعايزين نشيل اللي في المكان 1
        // بنخلي اللي في 2 يروح في 1، واللي في 3 يروح في 2
    for (int i = doctorIndex; i < doctorCount - 1; i++) {
        doctors[i] = doctors[i + 1];// كل دكتور يتحرك خطوة لليسار
    }
    // الخطوة 4: ننقص العداد بـ 1
    doctorCount--;
    cout << "Doctor removed successfully!\n";
}//DONE ! 1 ! الحمد لله  
int main() {
    int choice;  // متغير لتخزين اختيار المستخدم

    do {  // ابدأ حلقة تكرارية (تعمل مرة واحدة على الأقل)
        // عرض القائمة للمستخدم
        cout << "\n1. Add Doctor\n";     // الخيار 1: إضافة دكتور
        cout << "2. Remove Doctor\n";    // الخيار 2: حذف دكتور
        cout << "3. Exit\n";             // الخيار 3: خروج من البرنامج
        cout << "Enter choice: ";        // اطلب من المستخدم يدخل اختياره
        cin >> choice;                   // خزن الاختيار في المتغير choice

        // إذا اختار المستخدم 1، نادي دالة addDoctor
        if (choice == 1) {
            addDoctor();   // استدعاء دالة إضافة دكتور
        }
        // وإذا اختار المستخدم 2، نادي دالة removeDoctor
        else if (choice == 2) {
            removeDoctor();  // استدعاء دالة حذف دكتور
        }
        // لو اختار 3، الحلقة هتخلص لأن الشرط choice != 3 هيكون false
        else {
            cout << "ERROR: Invalid choice! Please enter 1, 2, 3.\n";
        }
    } while (choice != 3);  // استمر في التكرار طالما المستخدم لم يختر 3

    return 0;  // انتهى البرنامج بنجاح
}

>>>>>>> 37de5648dc83c903e1378dcfaba17d97d73c99b8





<<<<<<< HEAD
}
=======
>>>>>>> 37de5648dc83c903e1378dcfaba17d97d73c99b8
