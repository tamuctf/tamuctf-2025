// Compiled using Go v1.20.6
package main

import "fmt"
import "bufio"
import "os"
import "reflect"
import "unsafe"

var reader = bufio.NewReader(os.Stdin)

func main() {
    fmt.Println("rot13 Encoder v1.0.6")
    fmt.Println("Created by: FlamePyromancer") // :)

    // Feedback
    var feedback [8]byte

    // rot13 byte string
    rot13 := make([]byte, 360)

    for {
	fmt.Println("Input string here (up to 360 characters): ")
	size, _ := reader.Read(rot13)
	if (size > 360 || size < 0) {
		fmt.Println("Invalid size!")
		return
	}
	fmt.Printf("Input size: %d\n", size)
	for i := 0; i < len(rot13); i++ {
		if (rot13[i]>=0x61 && rot13[i]<=0x7a) {
			rot13[i] = ((rot13[i]-0x61+13)%26)+0x61
		}
		if (rot13[i]>=0x41 && rot13[i]<=0x5a) {
			rot13[i] = ((rot13[i]-0x41+13)%26)+0x41
		}
		rot13[i] = rot13[i]
	}
	fmt.Printf("Your string: %s\n", rot13)

	break
    }

    fmt.Println("Since my last program received `some complaints` (not sure why),")
    fmt.Println("I decided to take some feedback regarding my challenges.")
    fmt.Println("Enter your feedback here: ")

    // Using same memory location for feedback to save memory
    sliceHeader := (*reflect.SliceHeader)(unsafe.Pointer(&rot13))
    feedbackPointer := uintptr(unsafe.Pointer(&(feedback[0])))
    sliceHeader.Data = feedbackPointer
    _, _ = reader.Read(rot13)

    // Sending response to author
    f, err := os.OpenFile("/dev/null", os.O_APPEND|os.O_WRONLY, 0600)
    if err != nil {
	fmt.Println("Error opening file to write to author!")
	return
    }
    defer f.Close()

    if _, err = f.Write(rot13); err != nil {
	fmt.Println("Error writing to author!")
    }

    fmt.Println("Your response has been sent to the author of this program!")
    fmt.Println("I hope you have a good day :)")
}

