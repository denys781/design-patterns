#include <vector>
#include <memory>
#include <cstdint>

namespace Strategy
{
				template <class ContElementType>
				class ISortingStrategy
				{
				public:
								virtual ~ISortingStrategy() = default;

								virtual void Sort(std::vector<ContElementType>& data) const = 0;
				};

				template <class ContElementType>
				class BubbleSortStrategy : public ISortingStrategy<ContElementType>
				{
				public:
								void Sort(std::vector<ContElementType>& data) const override
								{
												std::uint16_t vectSize = data.size();

												for (std::uint16_t i = 0; i < vectSize - 1; ++i)
												{
																for (std::uint16_t j = 0; j < vectSize - i - 1; ++j)
																{
																				if (data[j] > data[j + 1])
																				{
																								std::swap(data[j], data[j + 1]);
																				}
																}
												}
								}
				};

				template <class ContElementType>
				class InstertSortStrategy : public ISortingStrategy<ContElementType>
				{
				public:
								void Sort(std::vector<ContElementType>& data) const override
								{
												std::uint16_t vectSize = data.size();

												for (std::uint16_t i = 1; i < vectSize; ++i)
												{
																ContElementType key = data[i];
																std::uint16_t j = i - 1;

																while (j >= 0 && data[j] > data)
																{
																				data[j + 1] = data[j];
																				--j;
																}
																data[j + 1] = key;
												}
								}
				};

				template <class ElementType>
				class SortingContext
				{
				public:
								// TODO: implement some interface and data_ memeber initializing

								void SetSortingStrategy(
												std::unique_ptr<ISortingStrategy<ElementType>>&& sortingStrategy
								)
								{
												sortingStrategy_ = std::move(sortingStrategy);
								}

								void Sort()
								{
												sortingStrategy_->Sort(data_);
								}

				private:
								std::vector<ElementType> data_;
								std::unique_ptr<ISortingStrategy<ElementType>> sortingStrategy_;
				};
}