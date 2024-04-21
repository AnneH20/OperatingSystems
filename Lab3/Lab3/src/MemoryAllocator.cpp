#include <algorithm>
#include <iostream>
#include <vector>

#include "MemoryAllocator.h"

MemoryAllocator::MemoryAllocator(std::size_t total_memory_size)
    : total_memory_size_(total_memory_size)
{
    // Initialize memory with a single block representing free memory
    memory_blocks_.push_back({0, total_memory_size_, "Free Memory"});
}

// NOTE: Utilized ChatGPT to help with debugging (see comments for anything further than debugging)

std::size_t MemoryAllocator::allocate(const std::string& process_id, std::size_t size)
{
    // TODO: Implement memory allocation logic

    // for each block in memory_blocks_
    for (auto block = memory_blocks_.begin(); block != memory_blocks_.end(); block++)
    {
        // Check that we have enough memory to begin with
        if (block->size >= size && block->process_id == "Free Memory")
        {
            // Allocate memory within the block
            std::size_t allocated_address = block->start_address;
            block->start_address += size;
            block->size -= size;

            // Remove the block if it becomes empty
            if (block->size == 0)
            {
                memory_blocks_.erase(block);
            }

            // Add the allocated memory block
            // ChatGPT gave me the logic for creating MemoryBlock allocated_block
            MemoryBlock allocated_block;
            allocated_block.start_address = allocated_address;
            allocated_block.size = size;
            allocated_block.process_id = process_id;

            // .push_back adds the allocated memory block
            memory_blocks_.push_back(allocated_block);

            // Return allocated_address
            return allocated_address;
        }
    }

    // No suitable memory block found, throw an exception (found on https://www.geeksforgeeks.org/exception-handling-c/)
    throw std::runtime_error("ERROR: No suitable memory block found");
}

void MemoryAllocator::deallocate(const std::string& process_id)
{
    // TODO: Implement memory deallocation logic

    // For all memory blocks:
   for (auto& block : memory_blocks_)
   {
        // Find the block assigned to the process id
        if (block.process_id == process_id)
        {
            // Set the process ID of the memory block to Free Memory
            block.process_id = "Free Memory";

            // Merge the contiguous free memory clocks back into a single memory block
            merge_free_blocks();

            // Memory deallocated successfully
            return;
        }
   }
    
    // If no memory block is found for the process ID, throw an exception (found on https://www.geeksforgeeks.org/exception-handling-c/)
    throw std::runtime_error("ERROR: No memory block found for the process ID.");
}

void MemoryAllocator::merge_free_blocks()
{
    // TODO: Implement logic to merge adjacent free memory blocks

    // For all memory blocks:
    for (auto block = memory_blocks_.begin(); block != memory_blocks_.end(); block++) 
    {
        // IF a memory block id is marked "Free Memory" AND
        // WHILE the next memory block is marked "Free Memory" THEN
        // Used https://www.geeksforgeeks.org/stdnext-in-cpp/ to get next memory block
        if (block->process_id == "Free Memory" && std::next(block) != memory_blocks_.end() && std::next(block)->process_id == "Free Memory") 
        {
            // Increase the size of the frist memory block by the size of the next memory block
            block->size += std::next(block)->size;

            // Remove next memory block
            block = memory_blocks_.erase(std::next(block));
            block--;           
        }
    }
}

std::vector<MemoryBlock>& MemoryAllocator::get_memory_layout()
{
    return memory_blocks_;
}
