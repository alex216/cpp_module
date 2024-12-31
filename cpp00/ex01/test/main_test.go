// main_test.go
package main

import (
	"bytes"
	"io"
	"os"
	"os/exec"
	"strings"
	"testing"
)

var (
	colorGreen = "\033[32m"
	colorRed   = "\033[31m"
	colorReset = "\033[0m"
)

func TestCppProgram(t *testing.T) {
	if os.Getenv("NO_COLOR") != "" {
		colorGreen = ""
		colorRed = ""
		colorReset = ""
	}

	tests := RetTestCase()

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			cmd := exec.Command("../phonebook")
			stdin, err := cmd.StdinPipe()
			if err != nil {
				t.Fatalf("Failed to open stdin pipe: %v", err)
			}

			var stdout bytes.Buffer
			cmd.Stdout = &stdout

			err = cmd.Start()
			if err != nil {
				t.Fatalf("Failed to start command: %v", err)
			}

			go func() {
				defer stdin.Close()
				io.WriteString(stdin, tt.input)
			}()

			err = cmd.Wait()
			if err != nil {
				t.Fatalf("Command failed to finish: %v", err)
			}

			output := stdout.String()
			if !strings.Contains(output, tt.expected) {
				t.Errorf("\n\n%s[Expected output]:%s\n%s\n\n%s[got]:%s\n%s\n\n",
					colorGreen, colorReset,
					strings.Join(strings.Split(addNewlineAfterPrompt2(addNewlineAfterPrompt(tt.expected)), "\n"), "\n"),
					colorRed, colorReset,
					strings.Join(strings.Split(addNewlineAfterPrompt2(addNewlineAfterPrompt(output)), "\n"), "\n"))
			}
		})
	}
}

func addNewlineAfterPrompt(input string) string {
	parts := strings.Split(input, Ps)

	for i := 0; i < len(parts)-1; i++ {
		parts[i] += Ps + "\n"
	}

	return strings.Join(parts, "")
}

func addNewlineAfterPrompt2(input string) string {
	parts := strings.Split(input, Index_prompt)

	for i := 0; i < len(parts)-1; i++ {
		parts[i] += Index_prompt + "\n"
	}

	return strings.Join(parts, "")
}
