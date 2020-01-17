   .cpu cortex-m0
   .text
   .align 1
   .global convert_case

convert_case:                                  //Compares every char to the ascii table values and converts them if a char is a letter
         push { lr }
         cmp r0, #'@'                     //the "@" comes before the "A" on ascii table
         ble return
         cmp r0, #'Z'
         ble caps
         cmp r0, #'`'                        //The "`" comes before the "a" on ascii table
         ble return
         cmp r0, #'z'
         ble small
         b return
caps:
         add r0, #('a' - 'A')              // creates lowercase from uppercase
         b return
small:
         sub r0, #('a' - 'A')              // create uppercase from lowercase
         b return
return:
         pop { pc }