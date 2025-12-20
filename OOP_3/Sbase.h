#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <map>
 class Sbase
{
	public:
		virtual int Get() = 0;
		virtual ~Sbase() {};

};
 class Skey : public Sbase{
 public:
	 int Get() override {
		 int x;
		 if (std::cin >> x) return x;
		 return -1;
	 }

 };
 class Squeue : public Sbase {
	 std::vector<int> data;
	 int pos;
 public:
	 Squeue(int size) : pos(0) {
		 std::random_device rd;
		 std::mt19937 mt(rd());
		 std::uniform_int_distribution<int> dist(1, 10);
		 for (int i = 0; i < size; i++)
			 data.push_back(dist(mt)); 
	 }

	 int Get() override {
		 if (pos < data.size())
			 return data[pos++];
		 return -1;
	 }
 };
 class Sfile : public Sbase {
	 std::ifstream fileReader;
	public:
		Sfile(const std::string& name) {
			fileReader.open(name);
		}
		int Get() override {
			int x;
			if (fileReader >> x)
				return x;
			return -1;
		}
		~Sfile() {
			fileReader.close();
		}
 };


 class Freq {
	protected:
		std::map<int, int> freq;
		int sum = 0;
	public:
		virtual void Calc(Sbase& src) {
			int x;
			while ((x = src.Get()) >= 0) {
				freq[x]++;
				sum += x;
			}
		}
		
		friend std::ostream& operator<<(std::ostream& os, const Freq& f) {
			os << "Frequency: \n";
			for (const auto& pair : f.freq)
				os << pair.first << ": " << pair.second << " times" << std::endl;
			os << "Sum: " << f.sum << std::endl;
			return os;
		}
		virtual ~Freq() {}
 };
 class Diap : public Freq {
	 int min=INT_MAX, max=0, count=0;
 public:
	 void Calc(Sbase& src) override {
		 int x;

		 while ((x = src.Get()) >= 0) {
			 if (x > max ) max = x;
			 if (x < min) min = x;
			 count ++;
		 }
	 }
	 friend std::ostream& operator<<(std::ostream& os, const Diap& d) {
		 os << "Min = " << d.min << std::endl;
		 os << "Max = " << d.max << std::endl;
		 os << "Count = " << d.count << std::endl;
		 return os;
	 }
 };