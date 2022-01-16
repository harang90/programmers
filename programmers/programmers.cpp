// programmers.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool primeTest(const int& num) {
    for (int i = 2; i < num; i++) {
        if ((num % i) == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;

    for (int k = 1; k <= numbers.size(); k++) {
        vector<int> ind;
        for (int i = 0; i < numbers.size() - k; i++) {
            ind.emplace_back(0);
        }
        for (int i = 0; i < k; i++) {
            ind.emplace_back(1);
        }
        do {
            std::vector<char> numVec;
            for (int i = 0; i < ind.size(); i++) {
                if (ind[i] == 1) numVec.emplace_back(numbers[i]);
            }
            if (numVec.empty()) continue;
            if (numVec[0] == '0') continue;
            if (k == 1 && numVec[0] == '1') continue;
            std::cout << "numVec:";
            for (auto iter = numVec.begin(); iter != numVec.end(); iter++) {
                std::cout << " " << *iter;
            }
            std::cout << std::endl;
            std::string numStr(numVec.begin(), numVec.end());
            int num = std::stoi(numStr);
            if (primeTest(num)) answer++;
        } while (std::next_permutation(ind.begin(), ind.end()));
    }

    return answer;
}

int main()
{
    vector<string> numbers{"17"};

    std::cout << "solution: " << solution(numbers[0]);

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
