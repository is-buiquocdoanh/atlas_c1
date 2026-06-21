// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from c1_driver:msg/Velinfo.idl
// generated code does not contain a copyright notice
#include "c1_driver/msg/detail/velinfo__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
c1_driver__msg__Velinfo__init(c1_driver__msg__Velinfo * msg)
{
  if (!msg) {
    return false;
  }
  // idsend
  // byte0
  // byte1
  // byte2
  // byte3
  // byte4
  // byte5
  // byte6
  // byte7
  return true;
}

void
c1_driver__msg__Velinfo__fini(c1_driver__msg__Velinfo * msg)
{
  if (!msg) {
    return;
  }
  // idsend
  // byte0
  // byte1
  // byte2
  // byte3
  // byte4
  // byte5
  // byte6
  // byte7
}

bool
c1_driver__msg__Velinfo__are_equal(const c1_driver__msg__Velinfo * lhs, const c1_driver__msg__Velinfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // idsend
  if (lhs->idsend != rhs->idsend) {
    return false;
  }
  // byte0
  if (lhs->byte0 != rhs->byte0) {
    return false;
  }
  // byte1
  if (lhs->byte1 != rhs->byte1) {
    return false;
  }
  // byte2
  if (lhs->byte2 != rhs->byte2) {
    return false;
  }
  // byte3
  if (lhs->byte3 != rhs->byte3) {
    return false;
  }
  // byte4
  if (lhs->byte4 != rhs->byte4) {
    return false;
  }
  // byte5
  if (lhs->byte5 != rhs->byte5) {
    return false;
  }
  // byte6
  if (lhs->byte6 != rhs->byte6) {
    return false;
  }
  // byte7
  if (lhs->byte7 != rhs->byte7) {
    return false;
  }
  return true;
}

bool
c1_driver__msg__Velinfo__copy(
  const c1_driver__msg__Velinfo * input,
  c1_driver__msg__Velinfo * output)
{
  if (!input || !output) {
    return false;
  }
  // idsend
  output->idsend = input->idsend;
  // byte0
  output->byte0 = input->byte0;
  // byte1
  output->byte1 = input->byte1;
  // byte2
  output->byte2 = input->byte2;
  // byte3
  output->byte3 = input->byte3;
  // byte4
  output->byte4 = input->byte4;
  // byte5
  output->byte5 = input->byte5;
  // byte6
  output->byte6 = input->byte6;
  // byte7
  output->byte7 = input->byte7;
  return true;
}

c1_driver__msg__Velinfo *
c1_driver__msg__Velinfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c1_driver__msg__Velinfo * msg = (c1_driver__msg__Velinfo *)allocator.allocate(sizeof(c1_driver__msg__Velinfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(c1_driver__msg__Velinfo));
  bool success = c1_driver__msg__Velinfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
c1_driver__msg__Velinfo__destroy(c1_driver__msg__Velinfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    c1_driver__msg__Velinfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
c1_driver__msg__Velinfo__Sequence__init(c1_driver__msg__Velinfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c1_driver__msg__Velinfo * data = NULL;

  if (size) {
    data = (c1_driver__msg__Velinfo *)allocator.zero_allocate(size, sizeof(c1_driver__msg__Velinfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = c1_driver__msg__Velinfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        c1_driver__msg__Velinfo__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
c1_driver__msg__Velinfo__Sequence__fini(c1_driver__msg__Velinfo__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      c1_driver__msg__Velinfo__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

c1_driver__msg__Velinfo__Sequence *
c1_driver__msg__Velinfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  c1_driver__msg__Velinfo__Sequence * array = (c1_driver__msg__Velinfo__Sequence *)allocator.allocate(sizeof(c1_driver__msg__Velinfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = c1_driver__msg__Velinfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
c1_driver__msg__Velinfo__Sequence__destroy(c1_driver__msg__Velinfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    c1_driver__msg__Velinfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
c1_driver__msg__Velinfo__Sequence__are_equal(const c1_driver__msg__Velinfo__Sequence * lhs, const c1_driver__msg__Velinfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!c1_driver__msg__Velinfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
c1_driver__msg__Velinfo__Sequence__copy(
  const c1_driver__msg__Velinfo__Sequence * input,
  c1_driver__msg__Velinfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(c1_driver__msg__Velinfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    c1_driver__msg__Velinfo * data =
      (c1_driver__msg__Velinfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!c1_driver__msg__Velinfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          c1_driver__msg__Velinfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!c1_driver__msg__Velinfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
