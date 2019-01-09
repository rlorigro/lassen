#include <callConsensus.h>
#include <iostream>

using std::cout;

//static char* paramsFile = "marginPhase/params/polish/polishParams.json";

static char *readArrayExample1[] = {
		"CATTTTTCTCCTCCACCTGCAACAGAAGATAAAAACGCGCATCACAAACTACTTTATTG",
		"CATTTTTCTCTCCGTCACGTAATAGGAAAACAGATGAAAATGTGCACCATAAAACGCATTTTTATTT",
		"CATTTTCTCTCTCCGTCACGACAGGAAACAGATGAAAATGGGCACAAGACCACAAACGCATTTTGAT",
		"CATTTTTCTCCGGTCATTTAATGAAAACAGATGGTACTGCGTATGTGACATAAACGCATTTTTATTT",
		"CATTTCCTCCGTCACTGCACAGGAAAACAGATGAAAATGCAAGTATGGACCCACAAAACGCATTTTATTT",
		"CATTTTTTCTCTCTCCGTCAGCTGCATTGAAAATGATGAAATGCGGGTATGACTATAAACGCATTTATTT",
		"CATTTTTTTTCTCTCCTCCACACACAGGAAACAGATGAAAAATGTATGTGACCATAAAACGCATTTTATTT",
		"TATTTTCTCCGTCATTGCAGGAAAACAGATGAAATGTAAAGTATGTGAATTACAAACGGTTTTTTTTATTT",
		"CATTTTTCTCCTCCGTCATTGCACAGGAGTCAGATGAAAATGCGCATGTGACCATAACGCATTTTTTTATTT",
		"CATTTTTCTCCTCCGTCATACCGTGAAACAGATGAAAAATGCGGGCATGGGACCATAAAACGCATTTTTATTT",
		"CATTTTTCTCCTCCGTCATTGCACAGGAAAACAGATGAAAACGTGGGGCATGTGACCATAAACGCATTTTTATT",
		"CATTTTCTCTCCTCGTGTTGCACAGGAAAACAGATGAAAAATGCGAGATATGTGATCCACAAACATTTTTATTT",
		"CATTTTTCTCCTCCGTCATTGCACAGGAAAATGATGAAAATGCGGGGCATGTGACCATAAAACGCATTTTTATTT",
		"CATTTTCTCTCTCCCTCGTCATTGCACAGGAAAACAGATGAAAATGCAGGGCATGTGACCATAAAACGCATTTTTT",
		"CATTTTCTCTCCTCCACATTGCACAGGAAAACAGATGAAAATGCGGCATGTGACCATAAAACGCATTTCTTTATTT",
		"CATTTTCTCCGTCAGTCAACAATATGAAAACAGATGAAACGCGGGCACGTGACCATAAAACGCATTTTTTTTATTT",
		"CATTTTTCTCCTCCGTCATTGCATTGTGGAACAGATGAAAATGCGGGGTATGTGAATCATAAAACGCATTTTATTT",
		"CATTTTTCTCTCCGTCATTGCATTAGAAAACAGGGATGAAAATGCGGGCATGTGACCATAAAAACGCATTTTTATTT",
		"CATTTTTCTCTCTCCTCCGTCATTGCACAGGAAAACAGATGAAAAATGCGCGTGACTATAAAACGCATTTTTATTTT",
		"CATTTTCCTCTCCCTCCGTCATTTGCACAGGAAAACAGATGAAAAAATGCGGAATGGCTATTATAAACATTTTTAACT",
		"CATTTTTTTCTCCTCTGTCATTGCACAGGAAAACAGATGAAAAATGCGTATGTGACCATAAAATCCATTTCTTTTATTT",
		"CATTTTTCTCCTCCGTCATTGCACAGGAAAATGATGAAAAAATGCGGGCATGTGACCATAAAACGTGCATTTTTTATTT",
		"CATTTTCTCTCTCCTCCGTGTTGCACAGGAAAACCAGATGAAAATGCGGAACATGTGTTCATAAAACGCATTTTTATTT",
		"CATTTTCTCTCCCTCCGTCATTGCACAGGAAAACAGATGAAAATGCAGGGCAATAATGACCATAAAACGCATTTTTATTT",
		"CATTTTCTCTCCTCTCGTCATTTGCACAGGAAGAGCAGATGAAAATGCAGGGCATGTGACCATAAAACGCATTTTTATTT",
		"CCATTTTCTCTCTCCCTCCGTCATTGCACAGGAAAAGCAGATGAAAAATGCGGGCATGTGACCATAAAACGCATTTTATTT",
		"CATTTTTTTCTCTCCTGTCATTGCACAGGAAACAAAGAGATGAAAAATGCGGGCATGTGACCATAAAACGCATTTTTATTT",
		"CATTTTTCTCTCCCTCCGTCATTGCATAGGAAAACAGATGAAAATGCGGGGTATGTGGACCATAAAACGCATTTTTTATTT",
		"CATTTTCTCTCTCCCTCCGTCATTGCACAGGGAAAACAGATGAAAATTGCGGGGCATGTGACCATAAAACGCATTTTTATTT",
		"CATTTTCTCTCTCCCTCCGTCATTTGCACAGGAAAACAGATGAAAAATGCGGGGCATGTGACCATAAAACGCATTTTTTATTT",
		"CATTTTTCTCTCCCTCCGTCACTGCACAGGAAAAACAGATGAAAATGCGGGGCATGCATCATAAAACGTATTTTTATTGAATTT",
		"CATTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACAGATAAGAAAAATGCAGGGGCATGTGACCATAAAACGCATTTTTATTT",
		"CATTTTTTCACTACTCTCCCTCCGTCGTACTGGAAAACAAACAGATAAATGCAGGGCATGTGACCATAAAACATTTTTTTATTT",
		"CATTTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACAGATAAAAAAAAATGCAGGGGCATGTGACCATAAAACATTTTTATTT",
		"CATTTTTTCTCTCTCTCGTGTTGCACACAGGAAAACAGATGAAAAATGCCGGGGCATCATGACCATAAAACGCGTTTTTTTATTT",
		"CATTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACAGATGAAAAATGCAGGGGCGTAACTGACCATAAAACGCATTTTTTATTT",
		"CATTTTTTCTCTCCTCCGTCATTGCACAGGAAAAATGTGATGAAAATGCGGGGTATGTGACCATAAAACGCATTTTTATGCTTCT",
		"CATTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACAGATGAAAAATGCGAGGACATGTGACCATAAAACGCATTTTTTTTATTT",
		"CATTTTCTCTCTCCCTCCGTCCATTGCACAGGAAAACAGATATAAAAAATGCAGGGCATCAAACCATAAAACATTTTTTTTATTT",
		"CATTTTTCTCTCCCTCCGTCATTGCAATAGGAAAACAGATATTTTGGTGTACCGCAAGTATGTGACCATAAAACGTATTTTTATTT",
		"CATTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACCAGATAGAAAAAATACAGGGCATGTGTTCATAAAGCACGCATTTTTATTT",
		"CATTTTTTTCTCTCTCCTCCGCTTTCACACACAGGAGTAAACAGATGAAAAATGTGGGCATGTGACCATAAAACGCATTTTTTATTT",
		"CATTTTCTCTCTCCCTCAAAATCATTTGCACAGGAAAACAGATAGAAAAATGCAACGGGGCATGTGATATAAAACGCATTTTTTATTT",
		"CATTTTCTACTCTCTCCCTCCGTCATTGCAGGAAAACAGATGAAAATGCAGGGAACATATATGACCATAAAACGCATTTTTTTTTATTT",
		"CATTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACAGATGAAAAAAGAGCTGGCATGCGGGGCATGTGACCATAAAACGCATTTTTTTGT"};

static char *trueReferenceExample1 = "CATTTTTCTCTCTCCCTCCGTCATTGCACAGGAAAACAGATGAAAAATGCGGGGCATGTGACCATAAAACGCATTTTTTATTT";


static char *readArrayExample2[] = {
			"GATGTAAAAATGACTGAGTTAGAACAGGCATAAATACATCTGT",
			"GATGTAAAAAAAAATGACAGAGAATAAAACTATCCTTATCTATT",
			"GATGTAAAAAGAAGCGGAAGTTAGAACAGGCATAAATACATCTGT",
			"GATGTAAAAAGAAATGACGGAAGAACAGAGCATAACACACATCTGT",
			"GATGTAAAAAAAGAATGATTTAGTTGAACAGAGCATAAATATCTGT",
			"GATGTAAAAAAAAGAAATGACGGAAGAACAGAGCATAACACATCTGT",
			"GATGTAAAAGAAATGGAGGTTAGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAGAAATGATTTGGAAGAACAGAGCATAAATATCTGT",
			"GATGTAAAAGAAATGACGGAAGTTAGAATATATATAACACACATCTGT",
			"GATGTAAAAAAAGAATGGACGGTTAGAACAGAGCACAACACACATCTGT",
			"GATGTAAAAAAGAATGATAAAGTTAGAATAGAGCATAAATAACATCTGT",
			"GATGTAAAAGAAATGTGGAAGTTAGAACAGAGCATAAATACACATCTAT",
			"GATGTAAAAAAAAAGAAATGAAGCTAGAACAGAGCATAAATACATCTGT",
			"GATGTAAAAAAAAAATGACCCGGAAGTTGAACAGAGCATAATACATCTGT",
			"GATGTAAAAAAGAAATGATTTAAAGGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAAGTGACGGAAGTTAAGACAGGCATAAATACACATCTGT",
			"GATGTAAAAAAGAAATGATTTGCTAGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAGAAATGATGGGTTAGAATAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAAGAAATGACGAGTTAGAACCAGAGCACCATCTACATCAT",
			"GATGTAAAAAAAAAAATGACGGAAGTTAGACAAGCATAAATACACATCTAT",
			"GATGTAAAAAAAAGAATGATTTGAAGTTAGAACAGAGCATAACACATCTGT",
			"GATGTAAAAGAAAATCGACTGAAGTTAGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAGAATGACGGAAGTTAGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAGAAATGACGGAGTTAGAACAGAGCATAAATACACATCTAT",
			"GATGTAAAAAAAAAGAAATGTGTGAGTTAAGACAGAGCATAAATACATCTAT",
			"GATGTAAAAAAGAAATGACGGAAGTTAAGACAGAGCATAAATACACATCTATT",
			"GATGTAAAAAAAAAAATGTGGAAGTTAAAACAGAGCATAAATACACATCTATT",
			"GATGCAAAAAAAAAGAAATGACGGAAGTTAAATTAGAGCATAAATACATCTGT",
			"GATGTAAAAAAAAGAAATGATTTGGAAGTTACAGAGCATAAATACACATCTGT",
			"GATGTAAAGAAAATGATTTTAGAAGTTAGAACAGAGCATAACACAATATCTGT",
			"GATAAAAAAAAAGGAATGATTGGAAGCTAGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAAGAAATGACGGAAGTTAAGACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAAATGACGGAAGTTCTGAAACAGGCATAAATACACATCTGTAT",
			"GATGTAAAAAGAATGATTTGAAGTTAGAACAGAGTATATTAAATACACATCTGT",
			"GATGTAAAAAAAAAGAAATGACGGAAGTTAAGACAGAGCATAAATACACATCTATT",
			"GATGTAAAAAAAAAGAAATGATTTGAAGCAGAACAGAGCATAAATACAAGATCTGT",
			"GATGTAAAAAAAAGAAGAAATGACGGAAGTTAAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAAAAGAAATGATTGAAGTTAGAAATATACATAAATACACATCTGT",
			"GATGTAAAAAAAAAGAAATGATTTTAAAGTGAACAGAGCATAAATACACACCTTGGT",
			"GATGTAAAAAAAAAAAAGAAATGACGGAAGTTGAACTAGGCTTATAAATACATCTGT",
			"GATGCCAAAAAAAAAAAGAAATGGCCAGAGTTAGAACAGAGCATAAATACACATCTGT",
			"GATGTAAAAAAAAAGAAATGCGGATTTGGAAGTTAGAACAGTATATAAAGCACACATCCGT" };

static char *trueReferenceExample2 = "GATGTAAAAAAAAAGAAATGACGGAAGTTAGAACAGAGCATAAATACACATCTGT";

int main(){
    int readNo;
    char* consensus;

    readNo = 45;
    consensus = callConsensus(readNo, readArrayExample1, trueReferenceExample1);

    cout << "REF: " << trueReferenceExample1 << "\n";
    cout << "OUT: " << consensus << "\n";

    readNo = 42;
    consensus = callConsensus(readNo, readArrayExample2, trueReferenceExample2);

    cout << "REF: " << trueReferenceExample2 << "\n";
    cout << "OUT: " << consensus << "\n";

    cout << typeid(readArrayExample1).name() << '\n';
    cout << typeid(readArrayExample1[0]).name() << '\n';
}