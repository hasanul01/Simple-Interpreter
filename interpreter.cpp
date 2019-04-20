#include <iostream>
#include <string>
using namespace std;

int state = 0; //inisialisai state

//pengecekan isi string dan membuat perintah cetak tidak case sensitif
void state0(string indeks){
	if(indeks[0] == 'C' || indeks[0] == 'c'){
		state = 1;	
	}else {
		state = 0;
	}
}

void state1(string indeks){
	if(indeks[1] == 'E' || indeks[1] == 'e'){
		state = 2;	
	}else {
		state = 0;	
	}
}

void state2(string indeks){
	if(indeks[2] == 'T' || indeks[2] == 't'){
		state = 3;
	}else {
		state = 0;
	}
}

void state3(string indeks){
	if(indeks[3] == 'A' || indeks[3] == 'a'){
		state = 4;
	}else{
		state = 0;
	}
}

void state4(string indeks){
	if(indeks[4] == 'K' || indeks[4] == 'k'){
		state = 5;	
	}else {
		state = 0;
	}
}

void state5(string indeks){
	if(indeks[5] == ' '){
		state = 6;
	}else {
		state = 0;
	}
}

void state6(string indeks){
	if(indeks[6] == '\"'){
		state = 7;
	}else {
		state = 0;
	}
}

void state7(string indeks){
	if(indeks[indeks.length()-2] == '\"'){
		state = 8;
	}
	else {
		state = 0;
	}
}

void state8(string indeks){
	if(indeks[indeks.length()-1] == ';'){
		state = 0;
	}
}

//inisialisasi a untuk membantu pengecekan
bool a = false;

//pengecekan string perstate
int cekState(string karakter){
	if(state == 0){
		state0(karakter);
		a = false;
		
		if(state == 1){
			state1(karakter);
			a = false;
			
			if(state == 2){
				state2(karakter);
				a = false;
				
				if(state == 3){
					state3(karakter);
					a = false;
					
					if(state == 4){
						state4(karakter);
						a = false;
						
						if(state == 5){
							state5(karakter);
							a = false;
							
							if(state == 6){
								state6(karakter);
								a = false;
								
								if(state == 7){
									state7(karakter);
									a = false;
									
									if(state == 8){
										state8(karakter);
										a = true;

										// memberikan keluaran isi string yang terkandung didalam double quote ""
										cout << "> ";
    									for(int i=7 ; i<karakter.length()-2 ; i++){
												cout << karakter[i];
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	//peringatan jika string tidak sesuai dengan aturan yang telah dicek
	if(a == false){
		cout << "Kode tidak tidak sesuai aturan!";
	}
}

int main(){
	string input;
	
	do{

		//mengambil input dari user
    	cout << "# ";
    	getline(cin,input);

			//pengecekan perintah selesai (tidak case sensitif) untuk penghentian program
    		if(input[0] == 's' || input[0] == 'S'){
    			
    			if(input[1] == 'e' || input[1] == 'E'){
    				
					if(input[2] == 'l' || input[2] == 'L'){
						
						if(input[3] == 'e' || input[3] == 'E'){
							
							if(input[4] == 's' || input[4] == 'S'){
								
								if(input[5] == 'a' || input[5] == 'A'){
									
									if(input[6] == 'i' || input[6] == 'I'){
										
										if(input[7] == ';'){

											//memberikan keluaran jika perintah selesai ditemukan
								    	a = false;
					          	cout << "> " << "Terimakasih sudah menggunakan compiler ini." << endl;
					           	return 0;
						       	}										
									}
								}
							}
						}
					}
				}
			}
			
			//terus mamanggil sub-prog cekState jika selesai tidak ditemukan
    	cekState(input);
		cout << endl;
		}while(true); //mengakhiri program ketika ditemukan selesai

    return 0;
}
