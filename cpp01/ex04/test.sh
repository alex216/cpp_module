make

echo "\n####[01] no nl"
echo "hello world42\c" > sample.txt
cat sample.txt
./mysed sample.txt 42 24
cat sample.txt
./mysed sample.txt 24 42
cat sample.txt

echo "\n\n####[02] with nl"
echo "hello world42" > sample.txt
cat sample.txt
./mysed sample.txt 42 24
cat sample.txt
./mysed sample.txt 24 42
cat sample.txt

echo "\n####[03] empty input"
./mysed sample.txt 42 ""
cat sample.txt

./mysed sample.txt "" 24
cat sample.txt

rm sample.txt
