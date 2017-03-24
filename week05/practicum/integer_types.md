| type              | bits  | values                                | values                            | `<cstdint>` type  |
|-------------------|-------|---------------------------------------|-----------------------------------|-------------------|
| char              | 8     | -2<sup>7</sup> to 2<sup>7</sup>-1     | -128 to 127                       | int8_t            |
| unsinged char     | 8     | 0 to 2<sup>8</sup>-1                  | 0 to 255                          | uint8_t           |
| short             | 16    | -2<sup>15</sup> to 2<sup>15</sup>-1   | -32768 to 32767                   | int16_t           |
| unsigned short    | 16    | 0 to 2<sup>16</sup>-1                 | 0 to 65535                        | uint16_t          |
| int               | 32    | -2<sup>31</sup> to 2<sup>31</sup>-1   | ~ -2 * 10<sup>9</sup> to ~ 2 * 10<sup>9</sup>   | int32_t       |
| unsigned int      | 32    | 0 to 2<sup>32</sup>-1                 | 0 to ~ 4 * 10<sup>9</sup>         | uint32_t          |
| long\*            | 32/64 |                                       |                                   | -                 |
| unsinged long\*   | 32/64 |                                       |                                   | size_t\*\*         |
| long long         | 64    | -2<sup>63</sup> to 2<sup>63</sup>-1   | ~ -9 * 10<sup>18</sup> to ~ 9 * 10<sup>18</sup> | int64_t       |
| unsigned long long    | 64    | 0 to 2<sup>64</sup>-1             | 0 to ~ 1.8 * 10<sup>19</sup>      | uint64_t         |

\* *Големината на `long` и `unsigned long` зависи от операционната система.
На 32-битов ОС са 32 битови числа, докато на 64-битов ОС са 64 битови.
Имат същата големина като указателите (`Т*`)*

\*\* *`size_t` не е дефиниран в `cstdint`, но го добавих за пълнота.*
