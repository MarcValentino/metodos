
using namespace std;

class Sistema{
public:
	float **linhas;
	Sistema(int dim);
	~Sistema();
	resolve();
	trocaLinhas(int index1, int index2);
	somaLinhas(int index1, int index2);
	float *multiplicaLinha(int index, int n);
}

void Sistema::Sistema(int dim){
	linhas = new float *[dim];
	for(int i = 0; i < dim; i++){
		linhas[i] = new float [dim];
		for(int j = 0; j < dim; j++) cin >> linhas[i][j] >> "%f";
	}
}

void Sistema::trocaLinhas(int index1, int index2){
	float *temp = linhas[index1];
	linhas[index1] = linhas[index2];
	linhas[index2] = temp;
}

void Sistema::somaLinhas(int index1, float *lin){
	for(int i = 0; i < sizeof(linhas[index1])/sizeof(float);i++) linhas[index1][i] += lin[i];
	
}

float *Sistema::multiplicaLinha(int index1, int n){
	float *res = new float[sizeof(linhas[index1])/sizeof(float)];
	for(int i = 0; i < sizeof(linhas[index1])/sizeof(float);i++) res[i] = linhas[index1][i] * n;
	return res;
}

void Sistema::resolve(){
	for (int i = 0; i < sizeof(linhas)/sizeof(float *); i++){
		if(linhas[i][i]==0){
			for(int j = 0;j < sizeof(linhas)/sizeof(float *); j++){
				int swapped = 0;
				if(linhas[j][i] != 0){
					trocaLinhas(i,j);
					swapped = 1;
					break;
				} 
				if(!swapped) return;

			}
		}
		for(int j = 0;j < sizeof(linhas)/sizeof(float *); j++){
			if(linhas[j][i] > 0){
				somaLinhas(j, multiplicaLinha(i, linhas[j][i]/linhas[i][i]));
			}
		}
	}

}

int main(){
	Sistema sis = Sistema(cin >> "%d");
	sis.resolve();

	return 0;
}