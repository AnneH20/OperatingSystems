#include <cse4733/MMU.hpp>

#include <iostream>
#include <stdexcept>

#include <algorithm>

namespace cse4733 {

MMU::MMU(int numPages, unsigned int base_address, unsigned int offset) :
    pageTable(numPages, -1),
    tlbHits{0},
    tlbMisses{0},
    m_base_address(base_address),
    m_offset(offset)
{}

void MMU::addEntry(unsigned int virtualAddress, unsigned int physicalAddress)
{
    // Check if the virtual address is valid
    if (virtualAddress < 0 || virtualAddress >= m_offset) {
        throw std::out_of_range("Virtual address is out of range");
    }

    // Add the entry to the TLB
    tlb.addEntry(virtualAddress, physicalAddress);

    // Also add the entry to the page table
    pageTable[virtualAddress] = physicalAddress;
}

unsigned int MMU::translateAddress(unsigned int virtualAddress) {

    // TODO:
    //
    // This function should translate a given virtual address to a physical address:
    //
    // 1. It should check that the address is within the 0 to offset range bounds.
    if (virtualAddress < 0 || virtualAddress >= m_offset) {
    // Throw an exception of std::out_of_range if it is not.
        throw std::out_of_range("Virtual Address is out of range");        
    }

    //
    // 2. It should check if the translation is in the TLB (a TLB hit).
    if (tlb.searchTLB(virtualAddress) != -1) {
    //    a. If it is, it should return the physical address from the TLB
    //       and increment the count of TLB hits.
        tlbHits++;
        return tlb.searchTLB(virtualAddress);
    }
    //
    // 3. If it is NOT in the TLB (a TLB miss), it should:
    else {
        
    //    a. It should look up the physical address in the page table with
    //       the 'virtual address' variable.
        unsigned int physicalAddress = pageTable[virtualAddress];
    //    b. If the physical address is not in the page table, it should
        if (physicalAddress == -1) {
    //          a) Set the physical address to the virtual address plus the base address
            physicalAddress = virtualAddress + m_base_address;
    //          b) Add the translation to the TLB
            tlb.addEntry(virtualAddress, physicalAddress);
    //          c) Store the physical address in the page table
            pageTable[virtualAddress] = physicalAddress;
        }
    //       2) Otherwise, it should:
        else {
    //       1) Create an entry in the TLB table.
            tlb.addEntry(virtualAddress, physicalAddress);
        }
    //    c. Increment the count of TLB misses.
        tlbMisses++;    
    // 4. Return the physical address.
        return physicalAddress;
    }
}

double MMU::getHitRatio() {
    // TODO:
    //   Calculate HIT ratio
    //   TLB HITs to total number of address translations
    double totalTranslations = tlbHits + tlbMisses;
    if (totalTranslations == 0) {
        return 0.0;
    }
    //   Return HIT ratio
    return static_cast<double>(tlbHits) / totalTranslations;
}

double MMU::getMissRatio() {
    // TODO:
    //   Calculate MISS ratio
    //   TLB MISSes to total number of address translations
    double totalTranslations = tlbHits + tlbMisses;
    if (totalTranslations == 0) {
        return 0.0;
    }
    //   Return HIT ratio
    return static_cast<double>(tlbMisses) / totalTranslations;
}


}  // namespace cse4733

