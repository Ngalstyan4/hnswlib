#include "hnswlib.h"
#include "hnsw_interface.h"

extern "C" {
    using namespace std;
    using idx_t = hnswlib::labeltype;

    void* hnsw_new_brute(int dimension, int max_elements) {
        //todo:: leaked "space" memory
        hnswlib::L2Space *space = new hnswlib::L2Space(dimension);
        hnswlib::AlgorithmInterface<float>* alg_hnsw = new hnswlib::BruteforceSearch<float>(space, max_elements);
        return (void*)alg_hnsw;
    }

    void* hnsw_new(int dimension, int max_elements, int M, int ef_construction) {
        //todo:: leaked "space" memory
        hnswlib::L2Space *space = new hnswlib::L2Space(dimension);
        hnswlib::AlgorithmInterface<float>* alg_hnsw = new hnswlib::HierarchicalNSW<float>(space, max_elements, M, ef_construction);
        return (void*)alg_hnsw;
    }

    void hnsw_add(void* hnsw, float* vector, long unsigned int label) {
        //todo:: use safer cast
        hnswlib::AlgorithmInterface<float>* alg_hnsw = (hnswlib::AlgorithmInterface<float>*)hnsw;
        // assert that vector[0] to vector[dim-1] are in range
        alg_hnsw->addPoint(vector, label);
    }

    void hnsw_search(void* hnsw, float* vector, int k, int* out_num_returned, float* out_distances, long unsigned int *out_labels) {
        int len;
        hnswlib::AlgorithmInterface<float>* alg_hnsw = (hnswlib::AlgorithmInterface<float>*)hnsw;
        // here searchKnn returns the result in the order of further first
        auto res = alg_hnsw->searchKnnCloserFirst(vector, k);

        *out_num_returned = len = res.size() < k ? res.size() : k;

        for (int i = 0; i < len; i++) {
            if (out_distances != NULL)
                out_distances[i] = res[i].first;
            if (out_labels != NULL)
                out_labels[i] = res[i].second;
        }
    }

    int hnsw_size(void* hnsw) {
        hnswlib::HierarchicalNSW<float>* alg_hnsw = (hnswlib::HierarchicalNSW<float>*)hnsw;
        return alg_hnsw->getCurrentElementCount();
    }

    void hnsw_save(void* hnsw, const char* filename) {
        hnswlib::AlgorithmInterface<float>* alg_hnsw = (hnswlib::AlgorithmInterface<float>*)hnsw;
        alg_hnsw->saveIndex(filename);
    }

    void* hnsw_load(const char* filename, int dimension, int max_elements) {
        //todo:: leaked "space" memory
        hnswlib::L2Space *space = new hnswlib::L2Space(dimension);
        hnswlib::HierarchicalNSW<float>* alg_hnsw = new hnswlib::HierarchicalNSW<float>(space, max_elements);
        alg_hnsw->loadIndex(filename, space, max_elements);
        return (void*)alg_hnsw;
    }

    void hnsw_destroy(void* hnsw) {
        hnswlib::AlgorithmInterface<float>* alg_hnsw = (hnswlib::AlgorithmInterface<float>*)hnsw;
        delete alg_hnsw;
    }
}
