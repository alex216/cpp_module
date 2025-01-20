#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Build
echo  "${BLUE}Building project...${NC}"
make

# Original content explanation
echo  "\n${YELLOW}Original test content will be:${NC} \"hello world42\""

# Test case 1: No newline
echo  "\n${GREEN}=== Test Case 1: Content without newline ===${NC}"
echo  "${BLUE}Creating test file...${NC}"
echo "hello world42\c" > sample.txt

echo  "${YELLOW}Initial content:${NC}"
cat sample.txt
echo  "${BLUE}Replacing '42' with '24'...${NC}"
./mysed sample.txt 42 24
echo  "${YELLOW}After first replacement:${NC}"
cat sample.txt.replace

echo  "${BLUE}Replacing '24' with '42'...${NC}"
./mysed sample.txt 24 42
echo  "${YELLOW}After second replacement:${NC}"
cat sample.txt.replace

# Test case 2: With newline
echo  "\n${GREEN}=== Test Case 2: Content with newline ===${NC}"
echo  "${BLUE}Creating test file...${NC}"
echo "hello world42" > sample.txt

echo  "${YELLOW}Initial content:${NC}"
cat sample.txt
echo  "${BLUE}Replacing '42' with '24'...${NC}"
./mysed sample.txt 42 24
echo  "${YELLOW}After first replacement:${NC}"
cat sample.txt.replace

echo  "${BLUE}Replacing '24' with '42'...${NC}"
./mysed sample.txt 24 42
echo  "${YELLOW}After second replacement:${NC}"
cat sample.txt.replace

# Test case 3: Empty string replacements
echo  "\n${GREEN}=== Test Case 3: Empty string tests ===${NC}"
echo  "${BLUE}Testing replacement with empty string...${NC}"
./mysed sample.txt 42 ""
echo  "${YELLOW}After replacing '42' with empty string:${NC}"
cat sample.txt.replace

echo  "${BLUE}Testing empty string as search pattern...${NC}"
./mysed sample.txt "" 24
echo  "${RED}Note: This should show error as empty search string is invalid${NC}"

# Cleanup
echo  "\n${BLUE}Cleaning up test files...${NC}"
rm -f sample.txt sample.txt.replace

echo  "${GREEN}Tests completed!${NC}"
