#include <stdint.h>

struct tu_source_location
{
    const char *file;
    uint32_t column;
    uint32_t line;
};

struct tu_type_descriptor
{
    uint16_t kind;
    uint16_t info;
    char name[];
};

struct tu_overflow_data
{
    struct tu_source_location location;
    struct tu_type_descriptor *type;
};

struct tu_shift_out_of_bounds_data
{
    struct tu_source_location location;
    struct tu_type_descriptor *left_type;
    struct tu_type_descriptor *right_type;
};

struct tu_invalid_value_data
{
    struct tu_source_location location;
    struct tu_type_descriptor *type;
};

struct tu_array_out_of_bounds_data
{
    struct tu_source_location location;
    struct tu_type_descriptor *array_type;
    struct tu_type_descriptor *index_type;
};

struct tu_type_mismatch_v1_data
{
    struct tu_source_location location;
    struct tu_type_descriptor *type;
    unsigned char log_alignment;
    unsigned char type_check_kind;
};

struct tu_negative_vla_data
{
    struct tu_source_location location;
    struct tu_type_descriptor *type;
};

struct tu_nonnull_return_data
{
    struct tu_source_location location;
};

struct tu_nonnull_arg_data
{
    struct tu_source_location location;
};

struct tu_unreachable_data
{
    struct tu_source_location location;
};

struct tu_invalid_builtin_data
{
    struct tu_source_location location;
    unsigned char kind;
};

static void print_location(struct tu_source_location loc)
{
    print("tinyubsan: at file %s, line %d, column %d", loc.file, loc.line, loc.column);
}

void __ubsan_handle_add_overflow(struct tu_overflow_data *data)
{
    print("tinyubsan: addition overflow");
    print_location(data->location);
};

void __ubsan_handle_sub_overflow(struct tu_overflow_data *data)
{
    print("tinyubsan: subtraction overflow");
    print_location(data->location);
}

void __ubsan_handle_mul_overflow(struct tu_overflow_data *data)
{
    print("tinyubsan: multiplication overflow");
    print_location(data->location);
}

void __ubsan_handle_divrem_overflow(struct tu_overflow_data *data)
{
    print("tinyubsan: division overflow");
    print_location(data->location);
}

void __ubsan_handle_negate_overflow(struct tu_overflow_data *data)
{
    print("tinyubsan: negation overflow");
    print_location(data->location);
}

void __ubsan_handle_pointer_overflow(struct tu_overflow_data *data, uintptr_t base, uintptr_t result)
{
    print("tinyubsan: pointer overflow, base pointer: %ld, result: %ld", base, result);
    print_location(data->location);
}

void __ubsan_handle_shift_out_of_bounds(struct tu_shift_out_of_bounds_data *data)
{
    print("tinyubsan: shift out of bounds");
    print_location(data->location);
}

void __ubsan_handle_load_invalid_value(struct tu_invalid_value_data *data)
{
    print("tinyubsan: invalid value load");
    print_location(data->location);
}

void __ubsan_handle_out_of_bounds(struct tu_array_out_of_bounds_data *data)
{
    print("tinyubsan: array out of bounds");
    print_location(data->location);
}

void __ubsan_handle_type_mismatch_v1(struct tu_type_mismatch_v1_data *data, uintptr_t ptr)
{
    if (!ptr)
    {
        print("tinyubsan: use of NULL pointer");
    }

    else if (ptr & ((1 << data->log_alignment) - 1))
    {
        print("tinyubsan: use of misaligned pointer");
    }
    else
    {
        print("tinyubsan: no space for object");
    }

    print_location(data->location);
}

void __ubsan_handle_vla_bound_not_positive(struct tu_negative_vla_data *data)
{
    print("tinyubsan: variable-length argument is negative");
    print_location(data->location);
}

void __ubsan_handle_nonnull_return(struct tu_nonnull_return_data *data)
{
    print("tinyubsan: non-null return is null");
    print_location(data->location);
}

void __ubsan_handle_nonnull_arg(struct tu_nonnull_arg_data *data)
{
    print("tinyubsan: non-null argument is null");
    print_location(data->location);
}

void __ubsan_handle_builtin_unreachable(struct tu_unreachable_data *data)
{
    print("tinyubsan: unreachable code reached");
    print_location(data->location);
}

void __ubsan_handle_invalid_builtin(struct tu_invalid_builtin_data *data)
{
    print("tinyubsan: invalid builtin");
    print_location(data->location);
}
