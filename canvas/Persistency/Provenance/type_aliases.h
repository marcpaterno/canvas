#ifndef canvas_Persistency_Provenance_type_aliases_h
#define canvas_Persistency_Provenance_type_aliases_h

#include "canvas/Persistency/Provenance/ProductID.h"
#include "canvas/Persistency/Provenance/BranchType.h"

#include <array>
#include <functional>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>


namespace art {

  class FileBlock;

  // Used for indices to find branch IDs by branchType, class type and process.
  // ... the key is the process name.
  using ProcessLookup     = std::map<std::string const, std::vector<ProductID>>;
  // ... the key is the friendly class name.
  using TypeLookup        = std::map<std::string const, ProcessLookup>;
  using PerBranchTypeLookup  = std::array<TypeLookup, NumBranchTypes>;
  using ProductLookup_t = PerBranchTypeLookup;
  using ViewLookup_t = std::array<ProcessLookup, NumBranchTypes>;

  namespace root {
    // Although this specific type alias does not rely on ROOT, it is
    // only used when ROOT fills an object of this type name.
    using ViewLookup_t = PerBranchTypeLookup;
  }

  using ProductListUpdatedCallback = std::function<void(FileBlock const&)>;

  inline
  namespace produced {
    // Used for determining if a product was produced in the current process
    using ProducedSet           = std::unordered_set<ProductID, ProductID::Hash>;
    using PerBranchTypeProduced = std::array<ProducedSet, NumBranchTypes>;
  }

  inline
  namespace presence {
    // Used for determining product presence information in input files
    using PresenceSet           = std::unordered_set<ProductID, ProductID::Hash>;
    using PerBranchTypePresence = std::array<PresenceSet, NumBranchTypes>;
  }

}

#endif /* canvas_Persistency_Provenance_type_aliases_h */

// Local variables:
// mode: c++
// End:
